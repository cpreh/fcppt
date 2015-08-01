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

\param _vec The vector to normalize

\warning
Behaviour is undefined if <code>length(v)</code> is close to zero.
*/
template<
	typename T,
	typename N,
	typename S
>
inline
fcppt::math::vector::object<
	T,
	N,
	S
>
normalize(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_vec
)
{
	return
		_vec
		/
		fcppt::math::vector::length(
			_vec
		);
}

}
}
}

#endif
