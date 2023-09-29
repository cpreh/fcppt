//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/has_key.hpp>
#include <fcppt/mpl/map/has_key_v.hpp>
#include <fcppt/mpl/map/object.hpp>

int main()
{
  using map = fcppt::mpl::map::
      object<fcppt::mpl::map::element<bool, int>, fcppt::mpl::map::element<float, double>>;

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::map::has_key<map,bool>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::map::has_key<map,float>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::mpl::map::has_key<map,double>::value);

  static_assert(fcppt::mpl::map::has_key_v<map,bool>);
  static_assert(fcppt::mpl::map::has_key_v<map,float>);
  static_assert(!fcppt::mpl::map::has_key_v<map,double>);
}
