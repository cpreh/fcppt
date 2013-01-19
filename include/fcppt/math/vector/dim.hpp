//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

#define FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename S1,\
	typename S2\
>\
object<\
	T,\
	N,\
	typename normal_storage<\
		T,\
		N\
	>::type\
> const \
operator op(\
	object<T, N, S1> const  &a,\
	dim::object<T, N, S2> const &b\
)\
{\
	object<\
		T,\
		N,\
		typename normal_storage<\
			T,\
			N\
		>::type\
	> ret(\
		a\
	);\
\
	for(typename N::value_type i = 0; i < ret.size(); ++i)\
		ret[i] op##= b[i];\
	return ret;\
}

FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(-)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(*)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(/)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(%)

#undef FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION

}
}
}

#endif
