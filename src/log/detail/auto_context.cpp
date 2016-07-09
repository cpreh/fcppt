//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


fcppt::log::detail::auto_context::auto_context(
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
:
	context_{
		_context
	},
	node_{
		_context.add(
			_location
		)
	}
{
}

fcppt::log::detail::auto_context::~auto_context()
{
	context_.remove(
		node_
	);
}

fcppt::log::context &
fcppt::log::detail::auto_context::context() const
{
	return
		context_;
}

fcppt::log::detail::context_tree const &
fcppt::log::detail::auto_context::node() const
{
	return
		node_;
}
