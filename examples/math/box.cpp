//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  // ![init_points]
  using box2i = fcppt::math::box::object<unsigned, 2>;

  box2i const box{box2i::min_t{box2i::vector{1U, 2U}}, box2i::max_t{box2i::vector{2U, 3U}}};
  // ![init_points]

  // ![init_size]
  box2i const box2{box2i::vector{1U, 2U}, box2i::dim{1U, 1U}};
  // ![init_size]

  std::cout << box << '\n';

  std::cout << box2 << '\n';

  // ![getters]
  std::cout << box.pos() << ", " << box.max() << '\n';
  std::cout << box.pos() << ", " << box.size() << '\n';
  // ![getters]
}
//]
