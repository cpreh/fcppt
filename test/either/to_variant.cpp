//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/variant.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/to_variant.hpp>
#include <fcppt/either/variant_type.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::to_variant", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using variant_type = fcppt::either::variant_type<either_int>;

  CHECK(fcppt::either::to_variant(either_int{42}) == variant_type{42});

  CHECK(
      fcppt::either::to_variant(either_int{std::string("failure")}) ==
      variant_type{std::string{"failure"}});
}

TEST_CASE("either::to_variant move", "[either]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using either_int = fcppt::either::object<std::string, int_movable>;

  using variant_type = fcppt::either::variant_type<either_int>;

  CHECK(fcppt::either::to_variant(either_int{int_movable{42}}) == variant_type{int_movable{42}});

  CHECK(
      fcppt::either::to_variant(either_int{std::string("failure")}) ==
      variant_type{std::string{"failure"}});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
