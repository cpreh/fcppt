//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_context_location.hpp>
#include <fcppt/log/detail/auto_context.hpp>


fcppt::log::detail::auto_context::auto_context(
	log::optional_context_location const &_context_location,
	log::object &_object
)
:
	context_location_(_context_location)
{
	if(
		context_location_
	)
		context_location_->context().add(
			context_location_->location(),
			_object
		);
}

fcppt::log::detail::auto_context::~auto_context()
{
	if(
		context_location_
	)
		context_location_->context().remove(
			context_location_->location()
		);
}

fcppt::log::optional_context_location const &
fcppt::log::detail::auto_context::context_location() const
{
	return context_location_;
}
