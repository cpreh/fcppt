//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/container/raw_vector/output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::raw_vector output", "[container],[raw_vector]")
{
  CHECK(fcppt::output_to_std_string(fcppt::container::raw_vector::object<int>{5, 10}) == "[5,10]");
}

FCPPT_CATCH_END
