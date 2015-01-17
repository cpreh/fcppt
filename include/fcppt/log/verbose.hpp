//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_VERBOSE_HPP_INCLUDED
#define FCPPT_LOG_VERBOSE_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/log/detail/level_if_enabled.hpp>


/**
\brief Log to a stream if its verbose level is enabled

\ingroup fcpptlog
*/
#define FCPPT_LOG_VERBOSE(\
	stream,\
	output\
)\
	FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(\
		stream,\
		fcppt::log::level::verbose,\
		output\
	)

#endif
