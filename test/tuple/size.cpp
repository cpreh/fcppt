//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::tuple::size<fcppt::tuple::object<int,bool>>::value == 2U);
  static_assert(std::is_same_v<
                fcppt::tuple::size<fcppt::tuple::object<int, bool>>,
                fcppt::tuple::size<fcppt::tuple::object<float, double>>>);
}
