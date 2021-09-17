//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/no_error_comparison.hpp>
#include <fcppt/either/no_error_output.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE("either::error", "[either]")
{
  using either_int = fcppt::either::error<int>;

  CHECK(either_int{42} == fcppt::either::make_failure<fcppt::either::no_error>(42));
}
