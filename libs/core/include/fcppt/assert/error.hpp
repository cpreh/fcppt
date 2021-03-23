//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ASSERT_ERROR_HPP_INCLUDED
#define FCPPT_ASSERT_ERROR_HPP_INCLUDED

#include <fcppt/assert/basic/terminate_conditional.hpp>

/**
\brief Asserts a condition in the middle of a function

\ingroup fcpptassert

Asserts that \a condition is true, calling <code>std::terminate</code> if it is
not. This macro should be used if an error occurs in the middle of a function
that should not happen.

\param condition The condition to check for
*/
#define FCPPT_ASSERT_ERROR(condition) FCPPT_ASSERT_BASIC_TERMINATE_CONDITIONAL(condition)

#endif
