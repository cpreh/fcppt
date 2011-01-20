//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context_location.hpp>
#include <fcppt/assert.hpp>

fcppt::log::context_location::context_location()
:
	context_(),
	location_()
{}

fcppt::log::context_location::context_location(
	log::context *const _context,
	log::location const &_location
)
:
	context_(_context),
	location_(_location)
{}

fcppt::log::context *
fcppt::log::context_location::context() const
{
	return context_;
}

fcppt::log::location const &
fcppt::log::context_location::location() const
{
	FCPPT_ASSERT(
		location_
	);

	return *location_;
}
