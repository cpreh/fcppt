//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object_fwd.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::array::size<fcppt::array::object<int, 2U>>::value == 2U);
  static_assert(std::is_same_v<
                fcppt::array::size<fcppt::array::object<int, 2>>,
                fcppt::array::size<fcppt::array::object<bool, 2>>>);
}
