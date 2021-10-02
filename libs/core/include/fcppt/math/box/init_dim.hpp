//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_INIT_DIM_HPP_INCLUDED
#define FCPPT_MATH_BOX_INIT_DIM_HPP_INCLUDED

#include <fcppt/math/box/detail/init.hpp>
#include <fcppt/math/dim/init.hpp>
#include <fcppt/math/vector/init.hpp>

namespace fcppt::math::box
{
/**
\brief Initializes a box from pairs of positions and sizes

\ingroup fcpptmathbox

Initializes an object of type \a Box by calling \a _function for every index.
The result \a _function must be a tuple where the first element is the position
and the second element is the size.

\tparam Box Must be a box

\tparam Function A (polymorphic) function of type
<code>fcppt::tuple::object<Box::value_type, Box::value_type> (Index)</code>
*/
template <typename Box, typename Function>
inline Box init_dim(Function const &_function)
{
  return fcppt::math::box::detail::init<Box>(
      [](auto const &_init_first) { return fcppt::math::vector::init<typename Box::vector>(_init_first); },
      [](auto const &_init_second) { return fcppt::math::dim::init<typename Box::dim>(_init_second); },
      _function);
}

}

#endif
