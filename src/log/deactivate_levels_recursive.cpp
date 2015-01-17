//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context.hpp>
#include <fcppt/log/deactivate_levels.hpp>
#include <fcppt/log/deactivate_levels_recursive.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


void
fcppt::log::deactivate_levels_recursive(
	fcppt::log::context &_context,
	fcppt::log::location const &_location,
	fcppt::log::level const _level
)
{
	_context.apply(
		_location,
		fcppt::log::tree_function(
			std::bind(
				&fcppt::log::deactivate_levels,
				std::placeholders::_1,
				_level
			)
		)
	);
}
