//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_PRINT_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_PRINT_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/gather_information.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/text.hpp>

#define FCPPT_ASSERT_PRINT_MESSAGE(\
	condition_arg,\
	message_arg\
) \
fcppt::io::cerr \
	<< \
	fcppt::assert_::make_message(\
		FCPPT_ASSERT_GATHER_INFORMATION(\
			condition_arg,\
			message_arg\
		) \
	) \
	<< FCPPT_TEXT('\n');

#endif
