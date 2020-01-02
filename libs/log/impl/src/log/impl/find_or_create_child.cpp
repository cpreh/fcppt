//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/find_child.hpp>
#include <fcppt/log/impl/find_or_create_child.hpp>
#include <fcppt/optional/from.hpp>


fcppt::log::detail::context_tree &
fcppt::log::impl::find_or_create_child(
	fcppt::log::detail::context_tree &_node,
	fcppt::log::name const &_name
)
{
	return
		fcppt::optional::from(
			fcppt::log::impl::find_child(
				_node,
				_name
			),
			[
				&_node,
				&_name
			]{
				return
					_node.push_back(
						fcppt::log::detail::context_tree_node{
							_name,
							_node.value().level()
						}
					);
			}
		).get();
}
