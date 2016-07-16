//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>


fcppt::log::detail::context_tree_node::context_tree_node(
	fcppt::log::name _name,
	fcppt::log::setting const &_setting
)
:
	name_{
		std::move(
			_name
		)
	},
	setting_{
		_setting
	}
{
}

fcppt::log::name const &
fcppt::log::detail::context_tree_node::name() const
{
	return
		name_;
}

fcppt::log::setting const &
fcppt::log::detail::context_tree_node::setting() const
{
	return
		setting_;
}

void
fcppt::log::detail::context_tree_node::setting(
	fcppt::log::setting const &_setting
)
{
	setting_ =
		_setting;
}
