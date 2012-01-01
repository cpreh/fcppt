//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_POST_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_POST_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/throw_message.hpp>

#define FCPPT_ASSERT_POST_MESSAGE(\
	condition,\
	message, \
	exception \
)\
FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	message, \
	exception \
)

#endif
