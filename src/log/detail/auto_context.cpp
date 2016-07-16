//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/impl/find_or_create_child.hpp>


fcppt::log::detail::auto_context::auto_context(
	fcppt::log::detail::context_tree &_node,
	fcppt::log::name const &_name
)
:
	node_{
		fcppt::log::impl::find_or_create_child(
			_node,
			_name
		)
	}
{
}

fcppt::log::detail::auto_context::~auto_context()
{
	// TODO: Cleanup nodes that are no longer needed
}

fcppt::log::detail::context_tree &
fcppt::log::detail::auto_context::node()
{
	return
		node_;
}

fcppt::log::detail::context_tree const &
fcppt::log::detail::auto_context::node() const
{
	return
		node_;
}
