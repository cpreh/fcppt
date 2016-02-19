//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR_HPP_INCLUDED

#define FCPPT_DETAIL_STRONG_TYPEDEF_BINARY_OPERATOR(\
	op\
) \
template< \
	typename T,\
	typename Tag\
> \
strong_typedef< \
	T, \
	Tag \
> \
operator op( \
	strong_typedef< \
		T, \
		Tag \
	> const &_a, \
	strong_typedef< \
		T, \
		Tag \
	> const &_b \
) \
{ \
	return \
		fcppt::strong_typedef< \
			T, \
			Tag \
		>( \
			_a.get() \
			op \
			_b.get() \
		); \
}

#endif
