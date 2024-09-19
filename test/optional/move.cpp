//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional move", "[optional]")
{
  using movable = fcppt::catch_::movable<std::string>;

  using optional_movable = fcppt::optional::object<movable>;

  optional_movable opta(movable("test"));

  optional_movable optb(std::move(opta));

  CHECK(optb == optional_movable{movable{"test"}});

  optional_movable optc(movable("test2"));

  optc = std::move(optb);

  CHECK(optc == optional_movable{movable{"test"}});

  optional_movable optd{};

  optd = optional_movable(movable("test3"));

  CHECK(optd == optional_movable{movable{"test3"}});

  optd = optional_movable(movable("test4"));

  CHECK(optd == optional_movable{movable{"test4"}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
