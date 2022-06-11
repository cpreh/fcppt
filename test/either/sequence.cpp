//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/loop_break_record.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/algorithm/map_record.hpp>
#include <fcppt/algorithm/map_tuple.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/sequence.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("either::sequence", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_int_vector = std::vector<either_int>;

  using int_vector = std::vector<int>;

  using result_type = fcppt::either::object<std::string, int_vector>;

  CHECK(
      fcppt::either::sequence<result_type>(either_int_vector{
          either_int{42},
          either_int{std::string("failure")},
          either_int{10},
          either_int{std::string("failure2")}}) == result_type{std::string{"failure"}});

  CHECK(
      fcppt::either::sequence<result_type>(either_int_vector{either_int{10}, either_int{20}}) ==
      result_type{int_vector{10, 20}});
}

TEST_CASE("either::sequence move", "[either]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using either_int = fcppt::either::object<std::string, int_movable>;

  using either_int_vector = std::vector<either_int>;

  using int_vector = std::vector<int_movable>;

  using result_type = fcppt::either::object<std::string, int_vector>;

  CHECK(
      fcppt::either::sequence<result_type>(fcppt::container::make<either_int_vector>(
          either_int{int_movable{10}}, either_int{int_movable{20}})) ==
      result_type{fcppt::container::make<int_vector>(int_movable{10}, int_movable{20})});
}

TEST_CASE("either::sequence tuple", "[either]")
{
  CHECK(
      fcppt::either::sequence<fcppt::either::object<std::string, fcppt::tuple::object<int, bool>>>(
          fcppt::tuple::make(
              fcppt::either::make_success<std::string>(0),
              fcppt::either::make_success<std::string>(false))) ==
      fcppt::either::make_success<std::string>(fcppt::tuple::make(0, false)));
}

TEST_CASE("either::sequence record", "[either]")
{
  FCPPT_RECORD_MAKE_LABEL(label1);
  FCPPT_RECORD_MAKE_LABEL(label2);

  CHECK(
      fcppt::either::sequence<fcppt::either::object<
          std::string,
          fcppt::record::
              object<fcppt::record::element<label1, int>, fcppt::record::element<label2, bool>>>>(
          fcppt::record::make(
              label1{} = fcppt::either::make_success<std::string>(0),
              label2{} = fcppt::either::make_success<std::string>(false))) ==
      fcppt::either::make_success<std::string>(
          fcppt::record::make(label1{} = 0, label2{} = false)));
}

FCPPT_CATCH_END
