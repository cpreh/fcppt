//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/loop_break_record.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/loop_break_tuple.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/map_record.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/map_tuple.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/record.hpp> // IWYU pragma: keep
#include <fcppt/catch/tuple.hpp> // IWYU pragma: keep
#include <fcppt/container/make.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/sequence_all.hpp>
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
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::sequence_all", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_int_vector = std::vector<either_int>;

  using result_type = fcppt::either::object<std::vector<std::string>, std::vector<int>>;

  CHECK(
      fcppt::either::sequence_all<result_type>(either_int_vector{
          either_int{42},
          either_int{std::string("failure")},
          either_int{10},
          either_int{std::string("failure2")}}) ==
      result_type{std::vector<std::string>{std::string{"failure"}, std::string{"failure2"}}});

  CHECK(
      fcppt::either::sequence_all<result_type>(either_int_vector{either_int{10}, either_int{20}}) ==
      result_type{std::vector<int>{10, 20}});
}

TEST_CASE("either::sequence_all move", "[either]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using either_int = fcppt::either::object<std::string, int_movable>;

  using either_int_vector = std::vector<either_int>;

  using result_type = fcppt::either::object<std::vector<std::string>, std::vector<int_movable>>;

  CHECK(
      fcppt::either::sequence_all<result_type>(fcppt::container::make<either_int_vector>(
          either_int{int_movable{10}}, either_int{int_movable{20}})) ==
      result_type{
          fcppt::container::make<std::vector<int_movable>>(int_movable{10}, int_movable{20})});
}

TEST_CASE("either::sequence_all tuple", "[either]")
{
  CHECK(
      fcppt::either::sequence_all<
          fcppt::either::object<std::vector<std::string>, fcppt::tuple::object<int, bool>>>(
          fcppt::tuple::make(
              fcppt::either::make_success<std::string>(0),
              fcppt::either::make_success<std::string>(false))) ==
      fcppt::either::make_success<std::vector<std::string>>(fcppt::tuple::make(0, false)));
}

TEST_CASE("either::sequence_all record", "[either]")
{
  FCPPT_RECORD_MAKE_LABEL(label1);
  FCPPT_RECORD_MAKE_LABEL(label2);

  CHECK(
      fcppt::either::sequence_all<fcppt::either::object<
          std::vector<std::string>,
          fcppt::record::
              object<fcppt::record::element<label1, int>, fcppt::record::element<label2, bool>>>>(
          fcppt::record::make(
              label1{} = fcppt::either::make_success<std::string>(0),
              label2{} = fcppt::either::make_success<std::string>(false))) ==
      fcppt::either::make_success<std::vector<std::string>>(
          fcppt::record::make(label1{} = 0, label2{} = false)));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
