//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::at_optional", "[container]")
{
  std::vector<int> const int_vector{1, 2};

  using optional_int_ref = fcppt::optional::reference<int const>;

  CHECK(
      fcppt::container::at_optional(int_vector, 1) ==
      optional_int_ref{fcppt::make_cref(int_vector[1])});

  CHECK(fcppt::container::at_optional(int_vector, 2) == optional_int_ref{});
}

FCPPT_CATCH_END
