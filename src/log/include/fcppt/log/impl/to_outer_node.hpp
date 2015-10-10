//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_TO_OUTER_NODE_HPP_INCLUDED
#define FCPPT_LOG_IMPL_TO_OUTER_NODE_HPP_INCLUDED

#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/impl/const_optional_outer_context_node.hpp>
#include <fcppt/log/impl/optional_outer_context_node.hpp>


namespace fcppt
{
namespace log
{
namespace impl
{

fcppt::log::impl::optional_outer_context_node
to_outer_node(
	fcppt::log::detail::context_tree &
);

fcppt::log::impl::const_optional_outer_context_node
to_outer_node(
	fcppt::log::detail::context_tree const &
);

}
}
}

#endif
