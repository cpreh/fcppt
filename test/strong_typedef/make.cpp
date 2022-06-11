//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
struct tag
{
};
}

FCPPT_CATCH_BEGIN

TEST_CASE("strong_typedef make", "[strongtypedef]")
{
  CHECK(fcppt::make_strong_typedef<tag>(42) == fcppt::strong_typedef<int, tag>{42});
}

FCPPT_CATCH_END
