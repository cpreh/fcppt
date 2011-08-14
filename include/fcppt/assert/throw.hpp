//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_THROW_HPP_INCLUDED
#define FCPPT_ASSERT_THROW_HPP_INCLUDED

#include <fcppt/assert/default_message.hpp>
#include <fcppt/assert/throw_message.hpp>

#define FCPPT_ASSERT_THROW(\
	condition,\
	exception\
) \
FCPPT_ASSERT_THROW_MESSAGE(\
	condition,\
	exception,\
	FCPPT_ASSERT_DEFAULT_MESSAGE\
)

#endif
