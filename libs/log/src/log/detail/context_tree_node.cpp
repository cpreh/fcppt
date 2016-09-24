//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast_to_enum.hpp>
#include <fcppt/const.hpp>
#include <fcppt/enum_size.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/active_level_int.hpp>
#include <fcppt/log/detail/context_tree_node.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


// TODO: Move this
namespace
{

fcppt::log::detail::active_level_int
convert_level(
	fcppt::log::optional_level const &_opt_level
)
{
	return
		fcppt::optional::maybe(
			_opt_level,
			fcppt::const_(
				fcppt::cast::size<
					fcppt::log::detail::active_level_int
				>(
					fcppt::enum_size<
						fcppt::log::level
					>::value
				)
			),
			[](
				fcppt::log::level const _level
			)
			{
				return
					fcppt::cast::enum_to_int<
						fcppt::log::detail::active_level_int
					>(
						_level
					);
			}
		);
}

}

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
		convert_level(
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
		fcppt::cast_to_enum<
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
		convert_level(
			_level
		);
}
