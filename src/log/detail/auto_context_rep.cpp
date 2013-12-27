//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/auto_context_rep.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


fcppt::log::detail::auto_context_rep::auto_context_rep(
	fcppt::log::context_location const &_context_location,
	fcppt::log::detail::context_tree &_node
)
:
	context_(
		_context_location.context()
	),
	location_(
		_context_location.location()
	),
	node_(
		_node
	)
{
}

void
fcppt::log::detail::auto_context_rep::context(
	fcppt::log::context &_context
)
{
	context_ =
		context_ref(
			_context
		);
}

void
fcppt::log::detail::auto_context_rep::node(
	fcppt::log::detail::context_tree &_node
)
{
	node_ =
		context_tree_ref(
			_node
		);
}

fcppt::log::context &
fcppt::log::detail::auto_context_rep::context() const
{
	return
		context_.get();
}

fcppt::log::detail::context_tree &
fcppt::log::detail::auto_context_rep::node() const
{
	return
		node_.get();
}

fcppt::log::location const &
fcppt::log::detail::auto_context_rep::location() const
{
	return
		location_;
}
