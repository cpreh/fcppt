//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_INFO_HPP_INCLUDED
#define FCPPT_LOG_INFO_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/log/detail/level_if_enabled.hpp>


/// Log to a stream if the info level is enabled
#define FCPPT_LOG_INFO(stream, x)\
	FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(stream, fcppt::log::level::info, x)

#endif
