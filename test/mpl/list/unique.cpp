//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/contains.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/mpl/list/unique.hpp>

int main()
{
  {
    using list = fcppt::mpl::list::unique<fcppt::mpl::list::object<int, int>>;

    static_assert(fcppt::mpl::list::size<list>::value == 1U);

    static_assert(fcppt::mpl::list::contains<list, int>::value);
  }

  {
    using list = fcppt::mpl::list::unique<fcppt::mpl::list::object<int, float>>;

    static_assert(fcppt::mpl::list::size<list>::value == 2U);

    static_assert(fcppt::mpl::list::contains<list, int>::value);

    static_assert(fcppt::mpl::list::contains<list, float>::value);
  }
}
