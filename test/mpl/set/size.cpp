//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(
      std::is_same_v<fcppt::mpl::set::size<fcppt::mpl::set::object<>>, fcppt::mpl::size_type<0U>>);

  static_assert(std::is_same_v<
                fcppt::mpl::set::size<fcppt::mpl::set::object<bool, int>>,
                fcppt::mpl::size_type<2U>>);
}
