//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/vector/object_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Checks the dimension of a vector

\ingroup fcpptmathvector
*/
template <typename Vector, fcppt::math::size_type Dim>
struct has_dim;

/// \cond FCPPT_DOXYGEN_DEBUG
template <typename T, fcppt::math::size_type N, typename S, fcppt::math::size_type Dim>
struct has_dim<fcppt::math::vector::object<T, N, S>, Dim> : fcppt::math::detail::dim_matches<Dim, N>
{
};
/// \endcond

}
}
}

#endif
