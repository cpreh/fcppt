//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/map/at.hpp>
#include <fcppt/mpl/map/insert.hpp>
#include <fcppt/mpl/map/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using map = fcppt::mpl::map::insert<fcppt::mpl::map::object<>,bool,int>;

  static_assert(std::is_same_v<fcppt::mpl::map::at<map,bool>,int>);
}
