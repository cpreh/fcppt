//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/not.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/strong_typedef_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/either.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/recursive.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/tuple.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/variant.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/container/insert.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/convert_const.hpp>
#include <fcppt/parse/custom_error.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/parse/make_convert_if.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/make_recursive.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/separator.hpp>
#include <fcppt/parse/string.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_tostring.hpp>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
namespace json
{
struct null
{
};

bool operator==(json::null const &, json::null const &);

bool operator==(json::null const &, json::null const &) { return true; }

class value
{
public:
  using type = fcppt::variant::object<
      json::null,
      bool,
      int,
      std::string,
      std::vector<fcppt::recursive<json::value>>,
      std::unordered_map<std::string, fcppt::recursive<json::value>>>;

  explicit value(type &&_impl) : impl_{std::move(_impl)} {}

  [[nodiscard]] type const &get() const { return impl_; }

private:
  type impl_;
};

template <typename Type>
fcppt::recursive<json::value> make_value(Type &&_value)
{
  return fcppt::recursive<json::value>{json::value{json::value::type{std::forward<Type>(_value)}}};
}

bool operator==(json::value const &, json::value const &);

bool operator==(json::value const &_left, json::value const &_right)
{
  return _left.get() == _right.get();
}

using array = std::vector<fcppt::recursive<json::value>>;

using object = std::unordered_map<std::string, fcppt::recursive<json::value>>;

class double_insert
{
};

using entries = std::vector<fcppt::tuple::object<std::string, fcppt::recursive<json::value>>>;

json::object make_object_(json::entries &&);

fcppt::either::object<fcppt::parse::custom_error<char>, json::object>
make_object(fcppt::parse::position<char>, json::entries &&);

json::object make_object_(json::entries &&_args)
{
  return fcppt::algorithm::fold(
      fcppt::container::make_move_range(std::move(_args)),
      object{},
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
      [](fcppt::tuple::object<std::string, fcppt::recursive<json::value>> &&_element, json::object &&_state) {
        if (fcppt::not_(fcppt::container::insert(
                _state,
                json::object::value_type{
                    std::move(fcppt::tuple::get<0>(_element)), std::move(fcppt::tuple::get<1>(_element))})))
        {
          throw
              // NOLINTNEXTLINE(hicpp-exception-baseclass)
              json::double_insert{};
        }

        return std::move(_state);
      });
}

fcppt::either::object<fcppt::parse::custom_error<char>, json::object>
make_object(fcppt::parse::position<char> const _pos, json::entries &&_args)
{
  return fcppt::either::try_call<json::double_insert>(
      [&_args] { return make_object_(std::move(_args)); },
      [_pos](json::double_insert const &) {
        return fcppt::parse::custom_error<char>{_pos, std::string{"Double insert"}};
      });
}

using start = fcppt::variant::object<json::array, json::object>;

}

using char_type = char;

using skipper = decltype(fcppt::parse::skipper::space());

template <typename Type>
using base = fcppt::parse::base_unique_ptr<Type, char_type, skipper>;

class parser
{
  FCPPT_NONMOVABLE(parser);

public:
  parser();

  ~parser() = default;

  [[nodiscard]] base<json::start> const &get() const { return start_; }

private:
  base<std::string> string_;

  base<json::value> value_;

  base<json::object> object_;

  base<json::array> array_;

  base<json::start> start_;
};

namespace parse = fcppt::parse;

parser::parser()
    : string_{parse::make_base<char_type, skipper>(
          parse::literal('"') >> parse::make_lexeme(*~parse::char_set{'"'}) >>
          parse::literal('"'))},
      value_{parse::make_base<char_type, skipper>(parse::construct<json::value>(
          parse::convert_const(parse::string("null"), json::null{}) |
          (parse::convert_const(parse::string("true"), true) |
           parse::convert_const(parse::string("false"), false)) |
          parse::int_<int>{} | fcppt::make_cref(string_) | fcppt::make_cref(array_) |
          fcppt::make_cref(object_)))},
      object_{parse::make_base<char_type, skipper>(parse::make_convert_if<char>(
          parse::literal('{') >> parse::separator(
                                     fcppt::make_cref(string_) >> parse::literal(':') >>
                                         parse::make_recursive(fcppt::make_cref(value_)),
                                     parse::literal{','}) >>
              parse::literal('}'),
          [](fcppt::parse::position<char> const _pos, json::entries &&_entries)
          { return json::make_object(_pos, std::move(_entries)); }))},
      array_{parse::make_base<char_type, skipper>(
          parse::literal('[') >>
          parse::separator(parse::make_recursive(fcppt::make_cref(value_)), parse::literal{','}) >>
          parse::literal(']'))},
      start_{parse::make_base<char_type, skipper>(
          fcppt::make_cref(array_) | fcppt::make_cref(object_))}
{
}

namespace json
{
fcppt::either::object<fcppt::parse::parse_string_error<char>, json::start>
parse_string(parser const &, std::string &&);

fcppt::either::object<fcppt::parse::parse_string_error<char>, json::start>
parse_string(parser const &_parser, std::string &&_input)
{
  return fcppt::parse::phrase_parse_string(
      fcppt::parse::deref(_parser.get()), std::move(_input), fcppt::parse::skipper::space());
}

fcppt::either::object<fcppt::parse::parse_string_error<char>, json::start>
make_success(json::start &&);

fcppt::either::object<fcppt::parse::parse_string_error<char>, json::start>
make_success(json::start &&_value)
{
  return fcppt::parse::make_parse_string_success<char>(std::move(_value));
}
}

}

namespace Catch
{
template <>
struct StringMaker<json::null>
{
  static std::string convert(json::null const &) { return std::string{"null"}; }
};

template <>
struct StringMaker<json::value>
{
  static std::string convert(json::value const &_value)
  {
    return fcppt::catch_::convert(_value.get());
  }
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::json base", "[parse]")
{
  parser const parser_{};

  CHECK(json::parse_string(parser_, std::string{}).has_failure());

  CHECK(
      json::parse_string(parser_, std::string{"[]"}) ==
      json::make_success(json::start{json::array{}}));

  CHECK(
      json::parse_string(parser_, std::string{"[1]"}) ==
      json::make_success(json::start{fcppt::container::make<json::array>(json::make_value(1))}));

  CHECK(
      json::parse_string(parser_, std::string{"[null]"}) ==
      json::make_success(
          json::start{fcppt::container::make<json::array>(json::make_value(json::null{}))}));

  CHECK(
      json::parse_string(parser_, std::string{"[true]"}) ==
      json::make_success(json::start{fcppt::container::make<json::array>(json::make_value(true))}));

  CHECK(
      json::parse_string(parser_, std::string{"[false]"}) ==
      json::make_success(
          json::start{fcppt::container::make<json::array>(json::make_value(false))}));

  CHECK(
      json::parse_string(parser_, std::string{"[ \"test\" ]"}) ==
      json::make_success(
          json::start{fcppt::container::make<json::array>(json::make_value(std::string{"test"}))}));

  CHECK(
      json::parse_string(parser_, std::string{"[1, true]"}) ==
      json::make_success(json::start{
          fcppt::container::make<json::array>(json::make_value(1), json::make_value(true))}));
}

TEST_CASE("parse::json object", "[parse]")
{
  parser const parser_{};

  CHECK(
      json::parse_string(parser_, std::string{"{}"}) ==
      json::make_success(json::start{json::object{}}));

  CHECK(
      json::parse_string(parser_, std::string{"{\"XY\":42}"}) ==
      json::make_success(json::start{fcppt::container::make<json::object>(
          json::object::value_type{std::string{"XY"}, json::make_value(42)})}));

  CHECK(
      json::parse_string(parser_, std::string{" { \"XY\" : 42 }"}) ==
      json::make_success(json::start{fcppt::container::make<json::object>(
          json::object::value_type{std::string{"XY"}, json::make_value(42)})}));

  CHECK(
      json::parse_string(
          parser_,
          std::string{"{"
                      "\"X\" : true,"
                      "\"Y\" : [ 10, false, null ],"
                      "\"Z\" : { \"A\" : \"test\", \"B\" : 20 }"
                      "}"}) ==
      json::make_success(json::start{fcppt::container::make<json::object>(
          json::object::value_type{std::string{"X"}, json::make_value(true)},
          json::object::value_type{
              std::string{"Y"},
              json::make_value(fcppt::container::make<json::array>(
                  json::make_value(10), json::make_value(false), json::make_value(json::null{})))},
          json::object::value_type{
              std::string{"Z"},
              json::make_value(fcppt::container::make<json::object>(
                  json::object::value_type{std::string{"A"}, json::make_value(std::string{"test"})},
                  json::object::value_type{std::string{"B"}, json::make_value(20)}))})}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
