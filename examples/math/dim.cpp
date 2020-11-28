//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/to_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
// ![conversion_to_vector]
using dim3 = fcppt::math::dim::static_<int, 3>;

using vector3 = fcppt::math::vector::static_<int, 3>;

void f()
{
  dim3 const d{1, 2, 3};

  vector3 const v(fcppt::math::dim::to_vector(d));

  std::cout << v << '\n';
}
// ![conversion_to_vector]

// ![conversion_from_vector]
void g()
{
  vector3 const v{1, 2, 3};

  dim3 const d(fcppt::math::vector::to_dim(v));

  std::cout << d << '\n';
}
// ![conversion_from_vector]

}

int main()
{
  f();

  g();
}
