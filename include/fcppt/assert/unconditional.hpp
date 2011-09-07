//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNCONDITIONAL_HPP_INCLUDED
#define FCPPT_ASSERT_UNCONDITIONAL_HPP_INCLUDED

#include <fcppt/assert/print_message.hpp>

#define FCPPT_ASSERT_UNCONDITIONAL(\
	condition_message,\
	message,\
	action\
) \
FCPPT_ASSERT_PRINT_MESSAGE(\
	condition_message,\
	message\
); \
action ; \

#endif
