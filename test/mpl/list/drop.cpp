//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/drop.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using list = fcppt::mpl::list::object<int, bool, char>;

  static_assert(std::is_same_v<
                fcppt::mpl::list::drop<list, fcppt::mpl::size_type<3U>>,
                fcppt::mpl::list::object<>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::drop<list, fcppt::mpl::size_type<2U>>,
                fcppt::mpl::list::object<char>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::drop<list, fcppt::mpl::size_type<1U>>,
                fcppt::mpl::list::object<bool, char>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::drop<list, fcppt::mpl::size_type<0U>>,
                fcppt::mpl::list::object<int, bool, char>>);
}
