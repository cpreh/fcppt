//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/math/vector/narrow_cast.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/push_back.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/vector/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using float2_vec = fcppt::math::vector::static_<float, 2>;

  float2_vec const vecf2(1.5F, 2.0F);

  using int2_vec = fcppt::math::vector::static_<int, 2>;

  using unsigned2_vec = fcppt::math::vector::static_<unsigned, 2>;

  // cast all the elements from float to unsigned int
  unsigned2_vec const vecui2(fcppt::math::vector::to_unsigned(
      fcppt::math::vector::structure_cast<int2_vec, fcppt::cast::float_to_int_fun>(vecf2)));

  std::cout << vecui2 << '\n';

  using unsigned3_vec = fcppt::math::vector::static_<unsigned, 3>;

  // construct a three dimensional vector from a two dimensional one
  unsigned3_vec const vecui3(fcppt::math::vector::push_back(vecui2, 42U));

  std::cout << vecui3 << '\n';

  // throw away the newly added element
  auto const vecui2n(fcppt::math::vector::narrow_cast<unsigned2_vec>(vecui3));

  std::cout << vecui2n << '\n';
}
