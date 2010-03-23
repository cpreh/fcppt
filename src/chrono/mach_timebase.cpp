//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/config.hpp>
#ifdef FCPPT_HAVE_MACH_TIME
#include "mach_timebase.hpp"
#include <fcppt/function_once.hpp>

namespace
{

struct mach_timebase_info ratio_;

void
init()
{
	FCPPT_FUNCTION_ONCE

	// TODO: what can this return?
	mach_timebase_info(
		&ratio_
	);
}

}

struct mach_timebase_info const
fcppt::chrono::mach_timebase()
{
	init();

	return ratio_;
}

#endif
