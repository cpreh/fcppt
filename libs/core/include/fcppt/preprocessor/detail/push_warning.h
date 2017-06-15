//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_PUSH_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_PUSH_WARNING_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	include <fcppt/preprocessor/pragma.h>
#	define FCPPT_PP_DETAIL_PUSH_WARNING \
	FCPPT_PP_PRAGMA(warning(push))
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/preprocessor/pragma.h>
#	define FCPPT_PP_DETAIL_PUSH_WARNING \
	FCPPT_PP_PRAGMA(GCC diagnostic push)
#else
	#define FCPPT_PP_DETAIL_PUSH_WARNING
#endif

#endif
