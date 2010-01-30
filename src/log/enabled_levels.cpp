//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/foreach_enumerator.hpp>

fcppt::log::enabled_level_array const
fcppt::log::enabled_levels(
	level::type const level_
)
{
	enabled_level_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		i,
		level
	)
		ret[
			i
		] = level_ <= i;

	return ret;
}
