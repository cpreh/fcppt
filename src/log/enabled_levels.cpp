//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/container/array_impl.hpp>
#include <fcppt/foreach_enumerator.hpp>

fcppt::log::enabled_level_array const
fcppt::log::enabled_levels(
	level::type const _level
)
{
	enabled_level_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		index,
		level
	)
		ret[
			index
		] =
			_level <= index;

	return ret;
}
