//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_message.hpp>

/**
\brief Terminates the program, also printing a message

\ingroup fcpptassert

Terminates the program, printing \a message. This assertion should be used when
an unimplemented feature is reached.

\param message The message to print
*/
#define FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE(message) \
  FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE(unimplemented, message)

#endif
