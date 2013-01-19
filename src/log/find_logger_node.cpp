//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/src/log/find_logger_node.hpp>
#include <fcppt/src/log/is_outer_node.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <functional>
#include <fcppt/config/external_end.hpp>


fcppt::log::detail::context_tree::iterator
fcppt::log::find_logger_node(
	fcppt::log::detail::context_tree &_tree
)
{
	return
		std::find_if(
			_tree.begin(),
			_tree.end(),
			std::bind(
				fcppt::log::is_outer_node,
				std::placeholders::_1
			)
		);
}
