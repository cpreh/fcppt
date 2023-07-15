//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::detail::sequence_result", "[parse]")
{
  CHECK(fcppt::parse::detail::sequence_result(fcppt::unit{}, fcppt::unit{}) == fcppt::unit{});

  CHECK(fcppt::parse::detail::sequence_result(fcppt::unit{}, 42) == 42);

  CHECK(fcppt::parse::detail::sequence_result(42, fcppt::unit{}) == 42);

  CHECK(fcppt::parse::detail::sequence_result(42, false) == fcppt::tuple::make(42, false));

  CHECK(
      fcppt::parse::detail::sequence_result(42, fcppt::tuple::make('X', false)) ==
      fcppt::tuple::make(42, 'X', false));

  CHECK(
      fcppt::parse::detail::sequence_result(
          fcppt::tuple::make('Y', true), fcppt::tuple::make('X', false)) ==
      fcppt::tuple::make('Y', true, 'X', false));

  CHECK(
      fcppt::parse::detail::sequence_result(
          'Y', fcppt::parse::detail::sequence_result(fcppt::unit{}, 42)) ==
      fcppt::tuple::make('Y', 42));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
