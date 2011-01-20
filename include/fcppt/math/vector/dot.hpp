//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the dot product between two vectors
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename basic<T, N, S1>::value_type
dot(
	basic<T, N, S1> const &l,
	basic<T, N, S2> const &r
)
{
	T result(static_cast<T>(0));

	for(
		typename basic<T, N, S1>::size_type i = 0;
		i < l.size();
		++i
	)
		result += l[i] * r[i];

	return result;
}

}
}
}

#endif
