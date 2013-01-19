//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_VARIANT_FWD_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/log/detail/inner_context_node_fwd.hpp>
#include <fcppt/log/detail/outer_context_node_fwd.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

typedef fcppt::variant::object<
	boost::mpl::vector2<
		fcppt::log::detail::inner_context_node,
		fcppt::log::detail::outer_context_node
	>
> context_tree_node_variant;

}
}
}

#endif
