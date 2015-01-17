//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <fcppt/config/external_end.hpp>


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
		size_type index(\
			0u\
		);\
		index < this->size();\
		++index\
	)\
		fcppt::math::detail::linear_access(\
			*this,\
			index\
		) \
		op \
		fcppt::math::detail::linear_access(\
			expr,\
			index\
		);\
\
	return *this;\
}

#endif
