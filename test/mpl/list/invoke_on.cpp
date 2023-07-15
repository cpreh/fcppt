//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/mpl/list/invoke_on.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("mpl::list::invoke_on", "[mpl]")
{
  using list_type = fcppt::mpl::list::object<int, float>;

  CHECK(fcppt::mpl::list::invoke_on<list_type>(
      1U,
      []<typename Type>(fcppt::tag<Type>) -> bool {
        return std::is_same_v<Type, float>;
      },
      fcppt::const_(false)));

  CHECK(fcppt::mpl::list::invoke_on<list_type>(
      0U,
      []<typename Type>(fcppt::tag<Type>) -> bool {
        return std::is_same_v<Type, int>;
      },
      fcppt::const_(false)));

  CHECK(fcppt::mpl::list::invoke_on<list_type>(
      2U, [](auto) -> bool { return false; }, fcppt::const_(true)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
