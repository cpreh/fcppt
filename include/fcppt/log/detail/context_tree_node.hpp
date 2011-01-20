//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED

#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace fcppt
{
namespace log
{
namespace detail
{

typedef variant::object<
	boost::mpl::vector2<
		inner_context_node,
		outer_context_node
	>
> context_tree_node;

}
}
}

#endif
