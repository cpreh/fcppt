//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: export
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/custom_error.hpp>
#include <fcppt/parse/make_convert_if.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: export
#include <fcppt/parse/position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
class my_struct
{
public:
  explicit my_struct(char const _x) : x_{_x} {}

  [[nodiscard]] char x() const { return x_; }

private:
  char x_;
};

bool operator==(my_struct const &_left, my_struct const &_right) { return _left.x() == _right.x(); }

std::ostream &operator<<(std::ostream &_stream, my_struct const &_value)
{
  return _stream << _value.x();
}

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::convert_if", "[parse]")
{
  auto const parser{fcppt::parse::make_convert_if<char>(
      fcppt::parse::char_{},
      [](fcppt::parse::position<char> const _pos, char const _value)
      {
        return fcppt::either::construct(
            _value == 'X',
            [_value] { return my_struct{_value}; },
            [_pos] {
              return fcppt::parse::custom_error<char>{_pos, "Invalid value!"};
            });
      })};

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_parse_string_success<char>(my_struct{'X'}));

  CHECK(fcppt::parse::parse_string(parser, std::string{"Y"}).has_failure());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
