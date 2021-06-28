//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
template<int Value>
using integral = std::integral_constant<int, Value>;
}

int main()
{
  static_assert(std::is_same_v<
                fcppt::mpl::list::interval<integral<0>, integral<0>>,
                fcppt::mpl::list::object<>>);

  static_assert(std::is_same_v<
                fcppt::mpl::list::interval<integral<3>, integral<5>>,
                fcppt::mpl::list::object<integral<3>, integral<4>>>);
}
