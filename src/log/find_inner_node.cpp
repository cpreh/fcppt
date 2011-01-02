//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "find_inner_node.hpp"
#include "inner_node_name.hpp"
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <algorithm>

fcppt::log::detail::context_tree::iterator
fcppt::log::find_inner_node(
	detail::context_tree &tree_,
	string const &name_
)
{
	return
		std::find_if(
			tree_.begin(),
			tree_.end(),
			inner_node_name(
				name_
			)
		);
}
