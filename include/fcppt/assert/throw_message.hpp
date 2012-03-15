//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_THROW_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_THROW_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/basic/conditional.hpp>
#include <fcppt/assert/basic/gather_information.hpp>


/**
\brief Throws an exception on a failed assertion, with an extra message on
failure

Throw \a exception if \a condition is false and also prints \a message. The
exception must have a constructor that takes an fcppt::assert_::information.

\param condition The condition to check for

\param exception The exception to throw on failure

\param message The message to print on failure
*/
#define FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	exception,\
	message\
) \
FCPPT_ASSERT_BASIC_CONDITIONAL(\
	condition,\
	throw exception(\
		FCPPT_ASSERT_BASIC_GATHER_INFORMATION(\
			condition,\
			message\
		)\
	) \
)

#endif
