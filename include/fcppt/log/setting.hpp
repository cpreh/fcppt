//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_SETTING_HPP_INCLUDED
#define FCPPT_LOG_SETTING_HPP_INCLUDED

#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/setting_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The setting for loggers

\ingroup fcpptlog
*/
class setting
{
public:
	FCPPT_LOG_DETAIL_SYMBOL
	explicit
	setting(
		fcppt::log::enabled_level_array const &
	);

	fcppt::log::enabled_level_array const &
	enabled_levels() const;
private:
	fcppt::log::enabled_level_array enabled_levels_;
};

}
}

#endif
