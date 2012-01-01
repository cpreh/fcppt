//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_UNARY_MINUS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_UNARY_MINUS_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_UNARY_MINUS \
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
operator -(\
	basic<\
		T,\
		N,\
		S\
	> const &a\
)\
{\
	basic<\
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
	for(\
		typename basic<T, N, S>::size_type i = 0;\
		i < ret.size();\
		++i\
	)\
		ret[i] = -ret[i];\
	return ret;\
}

#endif
