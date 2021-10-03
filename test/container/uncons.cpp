//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/uncons.hpp>
#include <fcppt/container/uncons_result.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/iterator/range_comparison.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::uncons", "[container]")
{
  using result_type = fcppt::container::uncons_result<std::vector<int>>;

  {
    std::vector<int> empty{};

    CHECK(fcppt::container::uncons(empty) == result_type{});
  }

  {
    std::vector<int> vec{1, 2, 3};

    CHECK(
        fcppt::container::uncons(vec) ==
        result_type{fcppt::tuple::make(
            fcppt::make_ref(vec[0]),
            fcppt::iterator::make_range(std::next(vec.begin()), vec.end()))}); // NOLINT(fuchsia-default-arguments-calls)
  }
}

FCPPT_CATCH_END
