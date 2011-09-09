//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED_HPP_INCLUDED

#if !defined(FCPPT_DISABLE_LOGGING)
#define FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(stream, l, x)\
{\
	if((stream).activated(l))\
		(stream).log(l, x);\
}
#else
#define FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(stream, l, x)
#endif

#endif
