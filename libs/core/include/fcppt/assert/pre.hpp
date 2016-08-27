//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_PRE_HPP_INCLUDED
#define FCPPT_ASSERT_PRE_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_conditional.hpp>


/**
\brief Asserts a pre condition of a function

\ingroup fcpptassert

Asserts that \a condition is true, calling <code>std::terminate</code> if it is
not. This macro should be used to check for a function's preconditions.

\param condition The condition to check for
*/
#define FCPPT_ASSERT_PRE(\
	condition\
)\
FCPPT_ASSERT_BASIC_TERMINATE_CONDITIONAL(\
	condition\
)

#endif
