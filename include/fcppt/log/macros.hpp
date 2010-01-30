//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_MACROS_HPP_INCLUDED
#define FCPPT_LOG_MACROS_HPP_INCLUDED

#include <fcppt/log/level.hpp>

#define FCPPT_LOG_LEVEL_IF_ENABLED(stream, l, x)\
	if((stream).activated(l))\
		(stream).log(l, x);

#define FCPPT_LOG_DEBUG(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::debug, x)

#define FCPPT_LOG_INFO(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::info, x)

#define FCPPT_LOG_WARNING(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::warning, x)

#define FCPPT_LOG_ERROR(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::error, x)

#define FCPPT_LOG_FATAL(stream, x)\
	FCPPT_LOG_LEVEL_IF_ENABLED(stream, fcppt::log::level::fatal, x)

#endif
