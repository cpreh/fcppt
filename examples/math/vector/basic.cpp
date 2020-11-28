//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//[vectorbasic
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using float3_vec = fcppt::math::vector::static_<float, 3>;

  // vectors can be constructed directly. Note that you cannot specify less
  // than N arguments (3 in this case) or you'll get a compiler error.
  float3_vec obj{1.F, 2.F, 3.F};

  std::cout << obj << '\n'; // prints something close to (1, 2, 3)
}
//]
