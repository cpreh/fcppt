//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/location.hpp>
#include <fcppt/log/location_setting.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::location_setting::location_setting(
	fcppt::log::location _location,
	fcppt::log::setting const &_setting
)
:
	location_{
		std::move(
			_location
		)
	},
	setting_{
		_setting
	}
{
}

fcppt::log::location const &
fcppt::log::location_setting::location() const
{
	return
		location_;
}

fcppt::log::setting const &
fcppt::log::location_setting::setting() const
{
	return
		setting_;
}
