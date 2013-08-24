//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_BASIC_PRINT_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_BASIC_PRINT_MESSAGE_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/assert/basic/gather_information.hpp>
#include <fcppt/cast/to_void.hpp>
#include <fcppt/io/cerr.hpp>


/**
\brief Prints an assert message to cerr, containing fcppt::assert_::information

\ingroup fcpptassert

Prints an assert message to <code>cerr</code>, consisting of information
gathered at the current code position, like file, line and function name, and
also the failed condition \a condition_arg and \a message_arg.
*/
#define FCPPT_ASSERT_BASIC_PRINT_MESSAGE(\
	condition_arg,\
	message_arg\
) \
fcppt::cast::to_void(\
	fcppt::io::cerr() \
		<< \
		fcppt::assert_::make_message(\
			FCPPT_ASSERT_BASIC_GATHER_INFORMATION(\
				condition_arg,\
				message_arg\
			) \
		) \
		<< FCPPT_TEXT('\n') \
)

#endif
