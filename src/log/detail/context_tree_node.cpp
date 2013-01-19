//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/detail/context_tree_node_variant.hpp>
#include <fcppt/variant/object_impl.hpp>


fcppt::log::detail::context_tree_node::context_tree_node(
	fcppt::log::detail::context_tree_node_variant const &_variant
)
:
	variant_(
		_variant
	)
{
}

fcppt::log::detail::context_tree_node_variant const &
fcppt::log::detail::context_tree_node::get() const
{
	return variant_;
}
