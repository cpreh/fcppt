//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "find_logger_node.hpp"
#include "is_outer_node.hpp"
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/tr1/functional.hpp>
#include <algorithm>

fcppt::log::detail::context_tree::iterator
fcppt::log::find_logger_node(
	detail::context_tree &_tree
)
{
	return
		std::find_if(
			_tree.begin(),
			_tree.end(),
			std::tr1::bind(
				log::is_outer_node,
				std::tr1::placeholders::_1
			)
		);
}
