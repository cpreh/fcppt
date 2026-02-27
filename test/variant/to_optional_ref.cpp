//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp> // IWYU pragma: keep
#include <fcppt/reference_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/reference.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/to_optional_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("variant::to_optional_ref", "[variant]")
{
  using variant = fcppt::variant::object<int, std::string>;

  {
    variant var(1);

    CHECK(
        fcppt::variant::to_optional_ref<int>(var) ==
        fcppt::optional::reference<int>(fcppt::make_ref(var.get_unsafe<int>())));

    CHECK(
        fcppt::variant::to_optional_ref<std::string>(var) ==
        fcppt::optional::reference<std::string>());
  }

  {
    variant const var(1);

    CHECK(
        fcppt::variant::to_optional_ref<int const>(var) ==
        fcppt::optional::reference<int const>(fcppt::make_cref(var.get_unsafe<int>())));

    CHECK(
        fcppt::variant::to_optional_ref<std::string const>(var) ==
        fcppt::optional::reference<std::string const>());
  }
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
