//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_THROW_HPP_INCLUDED
#define FCPPT_ASSERT_THROW_HPP_INCLUDED

#include <fcppt/assert/throw_message.hpp>
#include <fcppt/assert/basic/default_message.hpp>


/**
\brief Throws an exception on a failed assertion

\ingroup fcpptassert

Throw \a exception if \a condition is false. The exception must have a
constructor that takes an fcppt::assert_::information.

\param condition The condition to check for

\param exception The exception to throw on failure
*/
#define FCPPT_ASSERT_THROW(\
	condition,\
	exception\
) \
FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	exception,\
	FCPPT_ASSERT_BASIC_DEFAULT_MESSAGE\
)

#endif
