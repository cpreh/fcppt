//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/cross.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/point_rotate.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  fcppt::math::vector::static_<int, 2> vec(1, 2);

  using vec2f = fcppt::math::vector::static_<float, 2>;

  vec2f const vecf(1.F, 2.F);

  fcppt::math::vector::atan2(vecf);

  fcppt::math::vector::point_rotate(vecf, vecf, 3.F);

  fcppt::optional::maybe_void(fcppt::math::vector::normalize(vecf), [](vec2f const &_vec) {
    fcppt::io::cout() << _vec << FCPPT_TEXT('\n');
  });

  fcppt::io::cout() << vec << FCPPT_TEXT('\n') << fcppt::math::vector::length<float>(vec)
                    << FCPPT_TEXT('\n') << length(vecf) << FCPPT_TEXT('\n');

  using vec3d = fcppt::math::vector::static_<double, 3>;

  {
    vec3d const a(1.0, 0.0, 0.0);

    vec3d const b(0.0, 1.0, 0.0);

    fcppt::io::cout() << fcppt::math::vector::cross(a, b) << FCPPT_TEXT('\n');
  }

  using int_rect = fcppt::math::box::rect<int>;

  int_rect test_rect(int_rect::vector(1, 2), int_rect::dim(3, 2));

  fcppt::io::cout() << test_rect << FCPPT_TEXT('\n');
}
