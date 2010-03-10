//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/dim/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

// \cond
#define FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename S\
>\
basic<T, N, S> const \
operator op(\
	basic<T, N, S> const &a,\
	basic<T, N, S> const &b\
)\
{\
	return basic<T, N, S>(a) op##= b;\
}
// \endcond

FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(-)
FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(*)
FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(/)
FCPPT_MATH_MAKE_FREE_DIM_FUNCTION(%)

#undef FCPPT_MATH_MAKE_FREE_DIM_FUNCTION

template<
	typename T,
	typename N,
	typename S
>
basic<T, N, S> const
operator -(
	basic<T, N, S> a
)
{
	for(
		typename basic<T, N, S>::size_type i = 0;
		i < a.size();
		++i
	)
		a[i] = -a[i];
	return a;
}

template<
	typename T,
	typename N,
	typename S
>
basic<T, N, S> const
operator *(
	basic<T, N, S> a,
	T const &s
)
{
	return a *= s;
}

template<
	typename T,
	typename N,
	typename S
>
basic<T, N, S> const
operator *(
	T const &s,
	basic<T, N, S> const &a
)
{
	return a * s;
}

template<
	typename T,
	typename N,
	typename S
>
basic<T, N, S> const
operator /(
	basic<T, N, S> a,
	T const &s
)
{
	return a /= s;
}

}
}
}

#endif
