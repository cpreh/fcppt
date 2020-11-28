//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_POST_HPP_INCLUDED
#define FCPPT_ASSERT_POST_HPP_INCLUDED

#include <fcppt/assert/post_message.hpp>
#include <fcppt/assert/basic/default_message.hpp>

/**
\brief Asserts a post condition of a function

\ingroup fcpptassert

Asserts that \a condition is true, throw the exception \a exception if it is
not. The exception must have a constructor that takes an
fcppt::assert_::information. This macro should be used if an error occurs at
the end of a function, which is a result of failed function excecution,
although all pre conditions were true.

\param condition The condition to check for

\param exception The exception to throw if the condition is false
*/
#define FCPPT_ASSERT_POST(condition, exception) \
  FCPPT_ASSERT_POST_MESSAGE(condition, exception, FCPPT_ASSERT_BASIC_DEFAULT_MESSAGE)

#endif
