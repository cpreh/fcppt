//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_BASIC_GATHER_INFORMATION_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_GATHER_INFORMATION_HPP_INCLUDED

#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/function.hpp>
#include <fcppt/preprocessor/stringize.hpp>


/**
\brief Gathers fcppt::assert_::information at the current file and function

\ingroup fcpptassert

This macro expands to an fcppt::assert_::information, which gathers the current
source file, the line of the file, the function name, the failed condition
obtained from \a condition_arg, and the message obtained from \a message_arg.

\param condition_arg The condition of the assertion

\param message_arg The message of the assertion
*/
#define FCPPT_ASSERT_BASIC_GATHER_INFORMATION(\
	condition_arg,\
	message_arg\
)\
fcppt::assert_::information(\
	fcppt::assert_::file(\
		FCPPT_PP_FILE\
	),\
	fcppt::assert_::line(\
		__LINE__\
	),\
	fcppt::assert_::function(\
		FCPPT_PP_FUNCTION\
	),\
	fcppt::assert_::condition(\
		FCPPT_PP_STRINGIZE(\
			condition_arg\
		)\
	),\
	fcppt::assert_::message(\
		message_arg\
	) \
)

#endif
