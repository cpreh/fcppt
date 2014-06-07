//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED

#include <fcppt/log/detail/context_tree_node_fwd.hpp>
#include <fcppt/log/detail/context_tree_node_variant.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class context_tree_node
{
public:
	explicit
	context_tree_node(
		fcppt::log::detail::context_tree_node_variant const &
	);

	fcppt::log::detail::context_tree_node_variant const &
	get() const;
private:
	fcppt::log::detail::context_tree_node_variant variant_;
};

}
}
}

#endif
