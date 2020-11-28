//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/is_float_or_double.hpp>

int main()
{
  static_assert(fcppt::type_traits::is_float_or_double<float>::value);

  static_assert(fcppt::type_traits::is_float_or_double<double>::value);

  static_assert(!fcppt::type_traits::is_float_or_double<int>::value);
}
