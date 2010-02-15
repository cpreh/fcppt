//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DEF_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_MAKE_OP_DEF(name, op)\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
FCPPT_MATH_DETAIL_DEF_PRE \
 & \
FCPPT_MATH_DETAIL_DEF_PRE \
::operator op ( \
	FCPPT_MATH_DETAIL_DEF_PRE const &expr\
) \
{ \
	const_iterator right(\
		expr.begin()\
	);\
\
	for(\
		iterator left(\
			begin()\
		);\
		left != end();\
		++left, ++right\
	)\
		*left op *right;\
\
	return *this;\
}

#endif
