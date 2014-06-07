//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_POST_INC_DEC_OPERATOR_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_POST_INC_DEC_OPERATOR_HPP_INCLUDED


#define FCPPT_DETAIL_STRONG_TYPEDEF_POST_INC_DEC_OPERATOR(\
	op\
)\
template<\
	typename T,\
	typename Tag\
>\
fcppt::strong_typedef<\
	T,\
	Tag\
>\
operator op(\
	fcppt::strong_typedef<\
		T,\
		Tag\
	> &_value,\
	int\
)\
{\
	fcppt::strong_typedef<\
		T,\
		Tag\
	> const temp(\
		_value\
	);\
\
	op _value;\
\
	return temp;\
}

#endif
