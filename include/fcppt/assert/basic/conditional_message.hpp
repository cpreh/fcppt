//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_BASIC_CONDITIONAL_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_CONDITIONAL_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/unconditional_message.hpp>


/**
\brief Asserts that a condition is true, with an extra message on failure

\ingroup fcpptassert

Asserts that \a condition is true, taking \a action if it is not and also
printing \a message.

\param condition The condition to check for

\param message The message to print on failure

\param action The action to take on failure
*/
#define FCPPT_ASSERT_BASIC_CONDITIONAL_MESSAGE(\
	condition,\
	message, \
	action\
) \
if( \
	!(condition)\
)\
	FCPPT_ASSERT_BASIC_UNCONDITIONAL_MESSAGE(\
		condition, \
		message, \
		action \
	)

#endif
