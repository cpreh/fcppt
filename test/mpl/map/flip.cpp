//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/equal_v.hpp>
#include <fcppt/mpl/map/flip.hpp>
#include <fcppt/mpl/map/object.hpp>

int main()
{
  static_assert(fcppt::mpl::map::equal_v<
                fcppt::mpl::map::flip<fcppt::mpl::map::object<
                    fcppt::mpl::map::element<int, float>,
                    fcppt::mpl::map::element<char, bool>>>,
                fcppt::mpl::map::object<
                    fcppt::mpl::map::element<float, int>,
                    fcppt::mpl::map::element<bool, char>>>);
}
