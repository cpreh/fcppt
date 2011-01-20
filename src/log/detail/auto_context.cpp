//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/context.hpp>

fcppt::log::detail::auto_context::auto_context(
	context_location const &_location,
	object &_object
)
:
	location_(_location)
{
	if(
		location_.context()
	)
		location_.context()->add(
			location_.location(),
			_object
		);
}

fcppt::log::detail::auto_context::~auto_context()
{
	if(
		location_.context()
	)
		location_.context()->remove(
			location_.location()
		);
}

fcppt::log::context_location const
fcppt::log::detail::auto_context::location() const
{
	return location_;
}
