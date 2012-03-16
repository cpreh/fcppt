//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR_HPP_INCLUDED

#define FCPPT_DETAIL_STRONG_TYPEDEF_UNARY_OPERATOR(\
	op\
)\
template< \
	typename T, \
	typename Tag \
> \
strong_typedef< \
	T, \
	Tag \
> \
operator op( \
	strong_typedef< \
		T, \
		Tag \
	> const &_value \
) \
{ \
	return \
		strong_typedef< \
			T, \
			Tag \
		>( \
			op _value.get() \
		); \
}

#endif
