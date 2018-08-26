//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum/from_int.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/log/impl/convert_level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::detail::context_tree_node::context_tree_node(
	fcppt::log::name _name,
	fcppt::log::optional_level const &_level
)
:
	name_{
		std::move(
			_name
		)
	},
	atomic_level_{
		fcppt::log::impl::convert_level(
			_level
		)
	}
{
}

fcppt::log::detail::context_tree_node::context_tree_node(
	context_tree_node &&_other
)
:
	name_{
		std::move(
			_other.name_
		)
	},
	atomic_level_{
		_other.atomic_level_.load()
	}
{
}

fcppt::log::detail::context_tree_node::~context_tree_node()
{
}

fcppt::log::name const &
fcppt::log::detail::context_tree_node::name() const
{
	return
		name_;
}

fcppt::log::optional_level
fcppt::log::detail::context_tree_node::level() const
{
	return
		fcppt::enum_::from_int<
			fcppt::log::level
		>(
			atomic_level_.load()
		);
}

void
fcppt::log::detail::context_tree_node::level(
	fcppt::log::optional_level const &_level
)
{
	atomic_level_ =
		fcppt::log::impl::convert_level(
			_level
		);
}
