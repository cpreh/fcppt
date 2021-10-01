//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_STATIC_FWD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_STATIC_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_fwd.hpp>
#include <fcppt/math/vector/object_fwd.hpp>

namespace fcppt::math::vector
{
/**
\brief Typedef helper for static vectors

\ingroup fcpptmathvector

\tparam T The vector's <code>value_type</code>

See the introduction to fcppt::math::vector::object for more information on
static vectors (and on this class).
*/
template <typename T, fcppt::math::size_type N>
using static_ = fcppt::math::vector::object<T, N, fcppt::math::detail::static_storage<T, N>>;

}

#endif
