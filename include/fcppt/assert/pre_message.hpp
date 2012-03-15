//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_PRE_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_PRE_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_message_conditional.hpp>


/**
\brief Asserts a pre condition of a function, with an extra message on failure

\ingroup fcpptassert

Asserts that \a condition is true, calling <code>std::terminate</code> if it is
not and also printing \a message. This macro should be used to check for a
function's preconditions.

\param condition The condition to check for

\param message The message to print on failure
*/
#define FCPPT_ASSERT_PRE_MESSAGE(\
	condition,\
	message\
)\
FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL(\
	condition,\
	message\
)

#endif
