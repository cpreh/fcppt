//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_CONDITIONAL_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_CONDITIONAL_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/unconditional_message.hpp>

#define FCPPT_ASSERT_CONDITIONAL_MESSAGE(\
	condition,\
	message, \
	action\
) \
if( \
	!(condition)\
)\
	FCPPT_ASSERT_UNCONDITIONAL_MESSAGE(\
		condition, \
		message, \
		action \
	)

#endif
