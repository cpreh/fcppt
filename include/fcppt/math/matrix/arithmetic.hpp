//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

#define FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename M,\
	typename S\
>\
basic<T, N, M, S> const \
operator op(\
	basic<T, N, M, S> const &a,\
	basic<T, N, M, S> const &b)\
{\
	return basic<T, N, M, S>(a) op##= b;\
}

FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(-)

#undef FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION

template<
	typename T,
	typename N,
	typename M1,
	typename M2,
	typename S
>
basic<T, N, N, S> const
operator *(
	basic<T, M1, N, S> const &a,
	basic<T, N, M2, S> const &b)
{
	typedef basic<T, M1, M2, S> result_type;
	result_type ret;
	for(typename basic<T, M1, N, S>::size_type i = 0; i < M1::value; ++i)
		for(typename basic<T, N, M2, S>::size_type j = 0; j < M2::value; ++j)
		{
			typename result_type::value_type v(0);
			for(typename result_type::size_type r = 0; r < N::value; ++r)
				v += a[i][r] * b[r][j];
			ret[i][j] = v;
		}
	return ret;

}

}
}
}

#endif
