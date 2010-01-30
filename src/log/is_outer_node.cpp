//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "is_outer_node.hpp"
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <typeinfo>

bool
fcppt::log::is_outer_node(
	detail::context_tree const &node_
)
{
	return node_.value().type() == typeid(detail::outer_context_node);
}
