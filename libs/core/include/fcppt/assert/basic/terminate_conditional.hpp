//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_BASIC_TERMINATE_CONDITIONAL_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_TERMINATE_CONDITIONAL_HPP_INCLUDED

#include <fcppt/assert/basic/default_message.hpp>
#include <fcppt/assert/basic/terminate_message_conditional.hpp>

/**
\brief Calls terminate on a failed assertion

\ingroup fcpptassert

Calls terminate if \a condition is false.

\param condition The condition to check for
*/
#define FCPPT_ASSERT_BASIC_TERMINATE_CONDITIONAL(condition) \
  FCPPT_ASSERT_BASIC_TERMINATE_MESSAGE_CONDITIONAL(condition, FCPPT_ASSERT_BASIC_DEFAULT_MESSAGE)

#endif
