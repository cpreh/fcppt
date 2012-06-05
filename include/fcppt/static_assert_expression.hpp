//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STATIC_ASSERT_EXPRESSION_HPP_INCLUDED
#define FCPPT_STATIC_ASSERT_EXPRESSION_HPP_INCLUDED

#include <fcppt/detail/static_assert_failure.hpp>


/**
\brief Assert at compile time that a condition is true, using an expression

\ingroup fcpptvarious

This macro asserts at compile that \a cond is true, using an expression. It is
therefore preferred to use this macro to assert a condition in a function. It
will not generate any typedefs that might lead to warnings.
*/
#define FCPPT_STATIC_ASSERT_EXPRESSION(\
	cond\
)\
static_cast<\
	void\
>(\
	::fcppt::detail::static_assert_failure<\
		static_cast<\
			bool\
		>(\
			cond\
		)\
	>() \
)

#endif
