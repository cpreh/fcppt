//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_OPTIONAL_OUTER_CONTEXT_NODE_FWD_HPP_INCLUDED
#define FCPPT_SRC_LOG_OPTIONAL_OUTER_CONTEXT_NODE_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/log/detail/outer_context_node_fwd.hpp>


namespace fcppt
{
namespace log
{

typedef
fcppt::optional<
	fcppt::log::detail::outer_context_node &
>
optional_outer_context_node;

}
}

#endif
