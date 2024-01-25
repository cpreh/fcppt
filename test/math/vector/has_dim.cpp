//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/vector/has_dim.hpp>
#include <fcppt/math/vector/static.hpp>

int main()
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  static_assert(fcppt::math::vector::has_dim<ui2_vector, 2>::value);
}
