//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/unconditional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

#define FCPPT_ASSERT_UNIMPLEMENTED_MESSAGE(\
	message\
)\
FCPPT_ASSERT_UNCONDITONAL(\
	message,\
	std::terminate()\
)

#endif
