//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LOCATION_SETTING_HPP_INCLUDED
#define FCPPT_LOG_LOCATION_SETTING_HPP_INCLUDED

#include <fcppt/log/location.hpp>
#include <fcppt/log/location_setting_fwd.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief A pair of a location and a setting

\ingroup fcpptlog
*/
class location_setting
{
public:
	FCPPT_LOG_DETAIL_SYMBOL
	location_setting(
		fcppt::log::location,
		fcppt::log::setting const &
	);

	fcppt::log::location const &
	location() const;

	fcppt::log::setting const &
	setting() const;
private:
	fcppt::log::location location_;

	fcppt::log::setting setting_;
};

}
}

#endif
