//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename S1,\
	typename S2\
>\
basic<\
	T,\
	N,\
	typename normal_storage<\
		T,\
		N\
	>::type\
> const \
operator op(\
	basic<T, N, S1> const &a,\
	basic<T, N, S2> const &b\
)\
{\
	return \
		basic<\
			T,\
			N,\
			typename normal_storage<\
				T,\
				N\
			>::type\
		>(\
			a\
		)\
		op##= b;\
}

#endif
