//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_POST_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_POST_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/throw_message.hpp>


/**
\brief Asserts a post condition of a function, with an extra message on failure

\ingroup fcpptassert

Asserts that \a condition is true, throw the exception \a exception if it is
not and also printing \a message. The exception must have a constructor that
takes an fcppt::assert_::information. This macro should be used if an error
occurs at the end of a function, which is a result of failed function
excecution, although all pre conditions were true.

\param condition The condition to check for

\param message The message to print on failure

\param exception The exception to throw on failure
*/
#define FCPPT_ASSERT_POST_MESSAGE(\
	condition,\
	message, \
	exception \
)\
FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	message, \
	exception \
)

#endif
