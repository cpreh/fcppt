//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/tuple.hpp> // IWYU pragma: keep
#include <fcppt/container/make.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/partition.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::partition", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_int_vector = std::vector<either_int>;

  CHECK(
    fcppt::either::partition(either_int_vector{
          either_int{42},
          either_int{std::string("failure")},
          either_int{10},
          either_int{std::string("failure2")}})
    == fcppt::tuple::make(
         std::vector<std::string>{std::string{"failure"}, std::string{"failure2"}},
         std::vector<int>{42, 10}));
}

TEST_CASE("either::partition move", "[either]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using either_int = fcppt::either::object<std::string, int_movable>;

  using either_int_vector = std::vector<either_int>;

  using int_vector = std::vector<int_movable>;

  CHECK(
      fcppt::either::partition(
          fcppt::container::make<either_int_vector>(
              either_int{int_movable{10}}, either_int{std::string{"failure"}})) ==
      fcppt::tuple::make(
          std::vector<std::string>{std::string{"failure"}},
          fcppt::container::make<int_vector>(int_movable{10})));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
