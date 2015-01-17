//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED

#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Normalizes a vector and returns a copy.
\ingroup fcpptmathvector
\tparam N The vector's dimension
\tparam T The vector's <code>value_type</code>
\tparam S The vector's storage type
\param v The vector to normalize

\warning
Behaviour is undefined if <code>length(v)</code> is close to zero.
*/
template<
	typename T,
	typename N,
	typename S
>
object<T, N, S> const
normalize(
	object<T, N, S> const &v
)
{
	return v / vector::length(v);
}

}
}
}

#endif
