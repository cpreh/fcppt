//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/find_logger_node.hpp>
#include <fcppt/log/impl/optional_outer_context_node.hpp>
#include <fcppt/log/impl/to_outer_node.hpp>


fcppt::log::impl::optional_outer_context_node
fcppt::log::impl::find_logger_node(
	fcppt::log::detail::context_tree const &_tree
)
{
	return
		fcppt::algorithm::find_by_opt(
			_tree,
			[](
				fcppt::log::detail::context_tree const &_inner
			)
			{
				return
					fcppt::log::impl::to_outer_node(
						_inner
					);
			}
		);
}
