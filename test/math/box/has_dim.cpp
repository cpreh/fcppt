//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/box/has_dim.hpp>
#include <fcppt/math/box/object_impl.hpp>

int main()
{
  using ui2_box = fcppt::math::box::object<unsigned, 2>;

  static_assert(fcppt::math::box::has_dim<ui2_box, 2>::value);
}
