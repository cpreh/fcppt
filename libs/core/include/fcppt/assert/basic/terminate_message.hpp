//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/unconditional_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

/**
\brief Prints a message and terminates the program

\ingroup fcpptassert

Prints \a message and \a reason, and then calls <code>std::terminate</code>.

\param reason The reason for the assertion to fail

\param message The message to print
*/
#define FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE(reason, message) \
  FCPPT_ASSERT_BASIC_UNCONDITIONAL_MESSAGE(reason, message, std::terminate())

#endif
