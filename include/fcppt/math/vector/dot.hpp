//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the dot product of two vectors
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

The dot product is defined here:

http://en.wikipedia.org/wiki/Dot_product
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename object<T, N, S1>::value_type
dot(
	object<T, N, S1> const &l,
	object<T, N, S2> const &r
)
{
	T result(fcppt::literal<T>(0));

	for(
		typename object<T, N, S1>::size_type i = 0;
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
