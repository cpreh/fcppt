//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNCONDITIONAL_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_UNCONDITIONAL_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/message_and_action.hpp>
#include <fcppt/assert/unconditional.hpp>

#define FCPPT_ASSERT_UNCONDITIONAL_MESSAGE(\
	reason,\
	message,\
	action\
) \
FCPPT_ASSERT_MESSAGE_AND_ACTION(\
	FCPPT_ASSERT_UNCONDITIONAL,\
	message,\
	reason,\
	action \
)

#endif
