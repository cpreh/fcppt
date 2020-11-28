//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL_HPP_INCLUDED

#include <fcppt/assert/basic/conditional_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

/**
\brief Calls terminate on a failed assertion, with an extra message on failure

\ingroup fcpptassert

Calls terminate if \a condition is false and also prints \a message.

\param condition The condition to check for

\param message The message to print on failure
*/
#define FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL(condition, message) \
  FCPPT_ASSERT_BASIC_CONDITIONAL_MESSAGE(condition, message, std::terminate())

#endif
