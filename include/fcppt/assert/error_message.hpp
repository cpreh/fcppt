//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_ERROR_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_ERROR_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_message_conditional.hpp>


/**
\brief Asserts a condition in the middle of a function, with an extra message
on failure

\ingroup fcpptassert

Asserts that \a condition is true, calling <code>std::terminate</code> if it is
not and also printing \a message. This macro should be used if an error occurs
in the middle of a function that should not happen.

\param condition The condition to check for

\param message The message to print on failure
*/
#define FCPPT_ASSERT_ERROR_MESSAGE(\
	condition,\
	message\
)\
FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL(\
	condition,\
	message\
)

#endif
