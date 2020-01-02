//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/const_optional_context_tree_ref.hpp>
#include <fcppt/log/impl/find_child_const.hpp>
#include <fcppt/log/impl/find_child_tpl.hpp>


fcppt::log::impl::const_optional_context_tree_ref
fcppt::log::impl::find_child_const(
	fcppt::log::detail::context_tree const &_tree,
	fcppt::log::name const &_name
)
{
	return
		fcppt::log::impl::find_child_tpl(
			_tree,
			_name
		);
}
