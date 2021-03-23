//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_PUSH_BACK_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/push_back.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Pushes an element to the back of a vector.

\ingroup fcpptmathvector
*/
template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::vector::static_<T, N + 1>
push_back(fcppt::math::vector::object<T, N, S> const &_vector, T const &_value)
{
  return fcppt::math::detail::push_back<fcppt::math::vector::static_<T, N + 1>>(_vector, _value);
}

}
}
}

#endif
