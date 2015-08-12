//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>
#include <fcppt/log/impl/find_inner_node.hpp>
#include <fcppt/log/impl/inner_node_name.hpp>


fcppt::log::detail::optional_context_tree_ref const
fcppt::log::impl::find_inner_node(
	fcppt::log::detail::context_tree &_tree,
	fcppt::string const &_name
)
{
	return
		fcppt::algorithm::find_if_opt(
			_tree,
			fcppt::log::impl::inner_node_name(
				_name
			)
		);
}
