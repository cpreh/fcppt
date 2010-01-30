//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FIND_LOGGER_NODE_HPP_INCLUDED
#define FCPPT_LOG_FIND_LOGGER_NODE_HPP_INCLUDED

#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/variant/object_decl.hpp>

namespace fcppt
{
namespace log
{

detail::context_tree::iterator
find_logger_node(
	detail::context_tree &
);

}
}

#endif
