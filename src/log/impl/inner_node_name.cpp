//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/inner_context_node.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/log/impl/inner_node_name.hpp>
#include <fcppt/variant/match.hpp>


fcppt::log::impl::inner_node_name::inner_node_name(
	fcppt::string const &_name
)
:
	name_(
		_name
	)
{
}

fcppt::log::impl::inner_node_name::result_type
fcppt::log::impl::inner_node_name::operator()(
	fcppt::log::detail::context_tree const &_tree
) const
{
	return
		fcppt::variant::match(
			_tree.value().get(),
			[
				this
			](
				fcppt::log::detail::inner_context_node const &_inner_node
			)
			{
				return
					_inner_node.name()
					==
					name_;
			},
			[](
				fcppt::log::detail::outer_context_node const &
			)
			{
				return
					false;
			}
		);
}
