//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNREACHABLE_HPP_INCLUDED
#define FCPPT_ASSERT_UNREACHABLE_HPP_INCLUDED

#include <fcppt/assert/default_message.hpp>
#include <fcppt/assert/unreachable_message.hpp>

#define FCPPT_ASSERT_UNREACHABLE \
FCPPT_ASSERT_UNREACHABLE_MESSAGE(\
	FCPPT_ASSERT_DEFAULT_MESSAGE \
)

#endif
