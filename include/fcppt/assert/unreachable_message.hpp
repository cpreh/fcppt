//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNREACHABLE_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_UNREACHABLE_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_message.hpp>


/**
\brief Terminates the program, also printing a message

\ingroup fcpptassert

Prints \a message and terminates the program. This macro should be used when
an unreachable code part is executed.

\param message The message to print
*/
#define FCPPT_ASSERT_UNREACHABLE_MESSAGE(\
	message\
)\
FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE(\
	unreachable code,\
	message\
)

#endif
