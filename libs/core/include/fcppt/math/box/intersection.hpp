//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTION_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/init_max.hpp>
#include <fcppt/math/box/intersects.hpp>
#include <fcppt/math/box/null.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Calculates the intersection of two boxes (which is, again, a box)

\ingroup fcpptmathbox

If there is no intersection, the null box will be returned.
*/
template <typename T, fcppt::math::size_type N>
fcppt::math::box::object<T, N>
intersection(fcppt::math::box::object<T, N> const &_a, fcppt::math::box::object<T, N> const &_b)
{
  using result_type = fcppt::math::box::object<T, N>;

  return fcppt::math::box::intersects(_a, _b)
             ? fcppt::math::box::init_max<result_type>([&_a, &_b](auto const _index) {
                 FCPPT_USE(_index);

                 return fcppt::tuple::make(
                     std::max(
                         fcppt::math::vector::at<_index()>(_a.pos()),
                         fcppt::math::vector::at<_index()>(_b.pos())),
                     std::min(
                         fcppt::math::vector::at<_index()>(_a.max()),
                         fcppt::math::vector::at<_index()>(_b.max())));
               })
             : fcppt::math::box::null<result_type>();
}

}
}
}

#endif
