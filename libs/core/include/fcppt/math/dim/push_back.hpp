//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MATH_DIM_PUSH_BACK_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/push_back.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>

namespace fcppt::math::dim
{
/**
\brief Pushes an element to the back of a dim.

\ingroup fcpptmathdim
*/
template <typename T, fcppt::math::size_type N, typename S>
inline fcppt::math::dim::static_<T, N + 1U>
push_back(fcppt::math::dim::object<T, N, S> const &_dim, T const &_value)
{
  return fcppt::math::detail::push_back<fcppt::math::dim::static_<T, N + 1U>>(_dim, _value);
}

}

#endif
