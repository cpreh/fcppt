//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location_fwd.hpp>


fcppt::log::context_location::context_location(
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
:
	context_(
		_context
	),
	location_(
		_location
	)
{
}

fcppt::log::context &
fcppt::log::context_location::context() const
{
	return context_.get();
}

fcppt::log::location const &
fcppt::log::context_location::location() const
{
	return location_;
}
