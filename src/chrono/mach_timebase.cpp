//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/config.hpp>
#if defined(FCPPT_HAVE_MACH_TIME)
#include <fcppt/src/chrono/mach_timebase.hpp>

struct mach_timebase_info const
fcppt::chrono::mach_timebase()
{
	struct mach_timebase_info info;

	// TODO: what can this return?
	::mach_timebase_info(
		&info
	);

	return info;
}

#endif
