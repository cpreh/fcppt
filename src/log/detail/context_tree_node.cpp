//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>


fcppt::log::detail::context_tree_node::context_tree_node(
	fcppt::string _location_string,
	fcppt::log::setting const &_setting
)
:
	location_string_{
		std::move(
			_location_string
		)
	},
	setting_{
		_setting
	}
{
}

fcppt::string const &
fcppt::log::detail::context_tree_node::location_string() const
{
	return
		location_string_;
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
