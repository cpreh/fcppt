//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_HPP_INCLUDED
#define FCPPT_ASSERT_HPP_INCLUDED

#include <fcppt/assert_message.hpp>

/// Runtime assert macro that throws fcppt::assertion_failed if the condition does not hold
#define FCPPT_ASSERT(\
	condition\
)\
FCPPT_ASSERT_MESSAGE(\
	condition,\
	""\
)

#endif
