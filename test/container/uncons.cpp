//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/uncons.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::uncons", "[container]")
{
  {
    std::vector<int> empty{};

    CHECK(!fcppt::container::uncons(empty).has_value());
  }

  {
    std::vector<int> vec{1, 2, 3};

    fcppt::optional::maybe(
        fcppt::container::uncons(vec),
        [] { CHECK(false); },
        [&vec](
            fcppt::tuple::object<
                fcppt::reference<int>,
                std::ranges::subrange<std::vector<int>::iterator>> const &_value)
        {
          CHECK(fcppt::tuple::get<0U>(_value) == fcppt::make_ref(vec[0]));
          CHECK(
              std::ranges::equal(
                  std::ranges::subrange{std::next(vec.begin()), vec.end()},
                  fcppt::tuple::get<1U>(_value)));
        });
  }
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
