//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/map_array.hpp>
#include <fcppt/algorithm/map_record.hpp>
#include <fcppt/algorithm/map_tuple.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_vector = std::vector<int>;

using int_movable = fcppt::catch_::movable<int>;

using int_movable_vector = std::vector<int_movable>;

}

TEST_CASE("algorithm_map"
          "[algorithm_map]")
{
  CHECK(
      fcppt::algorithm::map<int_vector>(
          fcppt::container::make<int_movable_vector>(int_movable{1}, int_movable{2}),
          [](int_movable const &_value) { return _value.value(); }) == int_vector{1, 2});
}

TEST_CASE("algorithm_map move"
          "[algorithm_map]")
{
  CHECK(fcppt::algorithm::map<int_movable_vector>(int_vector{1, 2}, [](int const _value) {
          return int_movable{_value};
        }) == fcppt::container::make<int_movable_vector>(int_movable{1}, int_movable{2}));
}

TEST_CASE("algorithm_map mpl", "[algorithm_map]")
{
  CHECK(
      fcppt::algorithm::map<int_vector>(
          fcppt::mpl::list::object<std::integral_constant<int, 1>, std::integral_constant<int, 2>>{},
          [](auto const _value) {
            FCPPT_USE(_value);

            using type = fcppt::tag_type<decltype(_value)>;

            return type::value;
          }) == int_vector{1, 2});
}

TEST_CASE("algorithm_map array", "[algorithm_map]")
{
  using string_2_array = fcppt::array::object<std::string, 2>;

  CHECK(
      fcppt::algorithm::map<string_2_array>(
          fcppt::array::object<int, 2>{1, 2}, [](int const _value) -> std::string {
            return fcppt::output_to_std_string(_value);
          }) == string_2_array{std::string{"1"},std::string{ "2"}});
}

TEST_CASE("algorithm_map array move", "[algorithm_map]")
{
  FCPPT_MAKE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  using strong_int_movable_array = fcppt::array::object<strong_int_movable, 2>;

  CHECK(
      fcppt::algorithm::map<strong_int_movable_array>(
          fcppt::array::object<int_movable, 2>{int_movable{1}, int_movable{2}},
          [](int_movable &&_value) -> strong_int_movable {
            return strong_int_movable{std::move(_value)};
          }) == strong_int_movable_array{
                    strong_int_movable{int_movable{1}}, strong_int_movable{int_movable{2}}});
}

TEST_CASE("algorithm_map tuple", "[algorithm_map]")
{
  using result_tuple = fcppt::tuple::object<std::string, std::string>;

  CHECK(
      fcppt::algorithm::map<result_tuple>(
          fcppt::tuple::object<int, unsigned>{1, 2U}, [](auto const _value) -> std::string {
            return fcppt::output_to_std_string(_value);
          }) == result_tuple{"1", "2"});
}

TEST_CASE("algorithm_map record", "[algorithm_map]")
{
  FCPPT_RECORD_MAKE_LABEL(label1);
  FCPPT_RECORD_MAKE_LABEL(label2);

  using arg_type = fcppt::record::
      object<fcppt::record::element<label1, int>, fcppt::record::element<label2, unsigned>>;

  using result_type = fcppt::record::object<
      fcppt::record::element<label1, std::string>,
      fcppt::record::element<label2, std::string>>;

  CHECK(
      fcppt::algorithm::map<result_type>(
          arg_type{label1{} = 1, label2{} = 2U}, [](auto const _value) -> std::string {
            return fcppt::output_to_std_string(_value);
          }) == result_type{label1{} = std::string{"1"}, label2{} = std::string{"2"}});
}
