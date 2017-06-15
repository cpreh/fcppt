//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


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
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::vector::static_<
	T,
	N
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
