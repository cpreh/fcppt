//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/combine.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::combine", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  std::plus<int> const add{};

  CHECK(fcppt::optional::combine(optional_int(10), optional_int(20), add) == optional_int(30));

  CHECK(fcppt::optional::combine(optional_int(10), optional_int(), add) == optional_int(10));

  CHECK(fcppt::optional::combine(optional_int(), optional_int(20), add) == optional_int(20));

  CHECK(fcppt::optional::combine(optional_int(), optional_int(), add) == optional_int());
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
