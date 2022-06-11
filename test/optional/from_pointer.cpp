//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::from_pointer", "[optional]")
{
  using optional_ref = fcppt::optional::reference<int>;

  int value{0};

  CHECK(fcppt::optional::from_pointer(&value) == optional_ref{fcppt::make_ref(value)});

  int *const ptr(nullptr);

  CHECK(fcppt::optional::from_pointer(ptr) == optional_ref{});
}

FCPPT_CATCH_END
