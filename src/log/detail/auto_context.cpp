//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>


fcppt::log::detail::auto_context::auto_context(
	fcppt::log::detail::optional_context_location const &_context_location,
	fcppt::log::object &_object
)
:
	context_(
		_context_location
		?
			&_context_location->context()
		:
			nullptr
	),
	location_(
		_context_location
		?
			fcppt::log::optional_location(
				_context_location->location()
			)
		:
			fcppt::log::optional_location()
	),
	node_(
		_context_location
		?
			&context_->add(
				_context_location->location(),
				_object
			)
		:
			nullptr
	)
{
}

fcppt::log::detail::auto_context::~auto_context()
{
	if(
		node_
	)
		context_->remove(
			*node_
		);
}

fcppt::log::optional_location const
fcppt::log::detail::auto_context::location() const
{
	return location_;
}

fcppt::log::detail::context_tree const *
fcppt::log::detail::auto_context::node() const
{
	return node_;
}
