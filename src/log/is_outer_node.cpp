//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/src/log/is_outer_node.hpp>
#include <fcppt/variant/holds_type.hpp>


bool
fcppt::log::is_outer_node(
	fcppt::log::detail::context_tree const &_node
)
{
	return
		fcppt::variant::holds_type<
			fcppt::log::detail::outer_context_node
		>(
			_node.value().get()
		);
}
