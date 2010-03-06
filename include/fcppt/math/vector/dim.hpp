//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

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
basic<T, N, S1> const \
operator op(\
	basic<T, N, S1> a,\
	dim::basic<T, N, S2> const &b\
)\
{\
	for(typename N::value_type i = 0; i < a.size(); ++i)\
		a[i] op##= b[i];\
	return a;\
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
