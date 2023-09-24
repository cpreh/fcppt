//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/uncons.hpp>
#include <fcppt/container/uncons_result.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/iterator/range_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/optional/comparison.hpp>
#include <fcppt/tuple/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

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
            fcppt::iterator::make_range(std::next(vec.begin()), vec.end()))});
  }
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
