//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "find_inner_node.hpp"
#include "inner_node_name.hpp"
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

fcppt::log::detail::context_tree::iterator
fcppt::log::find_inner_node(
	detail::context_tree &_tree,
	string const &_name
)
{
	return
		std::find_if(
			_tree.begin(),
			_tree.end(),
			log::inner_node_name(
				_name
			)
		);
}
