//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/indices.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::indices<fcppt::mpl::list::object<int, float>>,
                fcppt::mpl::list::object<fcppt::mpl::size_type<0U>, fcppt::mpl::size_type<1U>>>);
}
