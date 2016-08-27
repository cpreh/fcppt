//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/setting.hpp>


fcppt::log::setting::setting(
	fcppt::log::enabled_level_array const &_enabled_levels
)
:
	enabled_levels_(
		_enabled_levels
	)
{
}

fcppt::log::enabled_level_array const &
fcppt::log::setting::enabled_levels() const
{
	return
		enabled_levels_;
}
