//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_BASIC_UNCONDITIONAL_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_UNCONDITIONAL_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/message_and_action.hpp>
#include <fcppt/assert/basic/unconditional.hpp>


/**
\brief Takes an unconditional action, also printing a message

\ingroup fcpptassert

Takes the unconditional action \a action, also printing a message with \a
reason and \a message.

\param reason The reason for the assertion to fail

\param message The message to print

\param action The action to take
*/
#define FCPPT_ASSERT_BASIC_UNCONDITIONAL_MESSAGE(\
	reason,\
	message,\
	action\
) \
FCPPT_ASSERT_BASIC_MESSAGE_AND_ACTION(\
	FCPPT_ASSERT_BASIC_UNCONDITIONAL,\
	message,\
	reason,\
	action \
)

#endif
