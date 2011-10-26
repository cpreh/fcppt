//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_TERMINATE_MESSAGE_CONDITIONAL_HPP_INCLUDED
#define FCPPT_ASSERT_TERMINATE_MESSAGE_CONDITIONAL_HPP_INCLUDED

#include <fcppt/assert/conditional_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

#define FCPPT_ASSERT_TERMINATE_MESSAGE_CONDITIONAL(\
	condition,\
	message\
) \
FCPPT_ASSERT_CONDITIONAL_MESSAGE(\
	condition,\
	message,\
	std::terminate()\
)

#endif
