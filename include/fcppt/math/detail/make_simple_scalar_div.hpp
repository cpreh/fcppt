//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_DIV_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_DIV_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_DIV \
template<\
	typename T,\
	typename N,\
	typename S\
>\
basic<\
	T,\
	N,\
	typename normal_storage<\
		T,\
		N\
	>::type\
> const \
operator /(\
	basic<T, N, S> a,\
	T const &s\
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
		/= s;\
}

#endif
