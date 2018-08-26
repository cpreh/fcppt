//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_BASIC_MESSAGE_AND_ACTION_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_MESSAGE_AND_ACTION_HPP_INCLUDED

#include <fcppt/assert/basic/print_message.hpp>


/**
\brief Executes a macro with an action and printing of a message

\ingroup fcpptassert

Executes \a macro, passing it an action that consists of printing a message
with \a reason and \a message and executing \a action afterwards.

\param macro The macro to invoke with the new action

\param message The message to print

\param reason The reason for the assertion

\param action The action to execute after printing the message
*/
#define FCPPT_ASSERT_BASIC_MESSAGE_AND_ACTION(\
	macro,\
	message,\
	reason,\
	action\
) \
macro(\
	(\
		FCPPT_ASSERT_BASIC_PRINT_MESSAGE(\
			reason,\
			message\
		),\
		action \
	)\
)


#endif
