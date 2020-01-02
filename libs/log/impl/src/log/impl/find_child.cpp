//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/find_child.hpp>
#include <fcppt/log/impl/find_child_tpl.hpp>
#include <fcppt/log/impl/optional_context_tree_ref.hpp>


fcppt::log::impl::optional_context_tree_ref
fcppt::log::impl::find_child(
	fcppt::log::detail::context_tree &_tree,
	fcppt::log::name const &_name
)
{
	return
		fcppt::log::impl::find_child_tpl(
			_tree,
			_name
		);
}
