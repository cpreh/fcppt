//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/equal.hpp>
#include <fcppt/mpl/map/object.hpp>

int main()
{
  static_assert(
      fcppt::mpl::map::equal<
          fcppt::mpl::map::
              object<fcppt::mpl::map::element<int, float>, fcppt::mpl::map::element<bool, double>>,
          fcppt::mpl::map::object<
              fcppt::mpl::map::element<bool, double>,
              fcppt::mpl::map::element<int, float>>>::value);

  static_assert(
      !fcppt::mpl::map::equal<
          fcppt::mpl::map::
              object<fcppt::mpl::map::element<int, float>, fcppt::mpl::map::element<bool, double>>,
          fcppt::mpl::map::object<
              fcppt::mpl::map::element<int, float>,
              fcppt::mpl::map::element<bool, float>>>::value);

  static_assert(
      !fcppt::mpl::map::equal<
          fcppt::mpl::map::
              object<fcppt::mpl::map::element<int, float>, fcppt::mpl::map::element<bool, double>>,
          fcppt::mpl::map::object<fcppt::mpl::map::element<int, float>>>::value);
}
