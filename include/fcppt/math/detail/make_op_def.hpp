//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#include <boost/preprocessor/tuple/rem.hpp>

#define FCPPT_MATH_DETAIL_MAKE_OP_DEF(\
	class_arity,\
	template_pre,\
	def_pre,\
	arg,\
	op\
)\
BOOST_PP_TUPLE_REM(class_arity)template_pre \
BOOST_PP_TUPLE_REM(class_arity)def_pre \
& \
BOOST_PP_TUPLE_REM(class_arity)def_pre \
::operator op( \
	BOOST_PP_TUPLE_REM(class_arity)arg const &expr\
) \
{\
	for(\
		size_type i = 0;\
		i < size();\
		++i\
	)\
		*(data() + i) op *(expr.data() + i);\
	\
	return *this;\
}

#endif
