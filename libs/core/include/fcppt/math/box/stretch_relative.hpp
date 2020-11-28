//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_STRETCH_RELATIVE_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_RELATIVE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/box/center.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/to_dim.hpp>

namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Stretch a box around its center by a given factor

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
fcppt::math::box::object<T, N> stretch_relative(
    fcppt::math::box::object<T, N> const &_box,
    typename fcppt::math::box::object<T, N>::vector const &_factors)
{
  auto const dim(_box.size() * fcppt::math::vector::to_dim(_factors));

  return fcppt::math::box::object<T, N>(
      fcppt::math::box::center(_box) -
          (fcppt::math::dim::to_vector(dim) / fcppt::literal<T>(2)).get_unsafe(),
      dim);
}

}
}
}

#endif
