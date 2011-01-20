//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_HPP_INCLUDED

#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/container/tree/object_fwd.hpp>

namespace fcppt
{
namespace log
{
namespace detail
{

typedef fcppt::container::tree::object<
	context_tree_node
> context_tree;

}
}
}

#endif
