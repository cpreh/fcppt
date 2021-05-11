//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/init_dim.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::box::init_dim", "[math],[box]")
{
  using box2 = fcppt::math::box::rect<fcppt::math::size_type>;

  CHECK(
      fcppt::math::box::init_dim<box2>(
          []<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>) {
            return fcppt::tuple::make(Index, Index);
          }) == box2(box2::vector(0U, 1U), box2::dim(0U, 1U)));
}
