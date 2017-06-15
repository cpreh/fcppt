//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_FWD_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_FWD_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/log/detail/context_tree_node_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

typedef
fcppt::container::tree::object<
	fcppt::log::detail::context_tree_node
>
context_tree;

}
}
}

#endif
