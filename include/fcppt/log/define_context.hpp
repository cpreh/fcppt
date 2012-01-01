//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context.hpp>

#define FCPPT_LOG_DEFINE_CONTEXT(\
	name\
)\
fcppt::log::context & \
name()\
{\
	static fcppt::log::context ret;\
	\
	return ret; \
}

#endif
