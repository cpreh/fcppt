//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_POP_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_POP_WARNING_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	include <fcppt/preprocessor/pragma.h>
#	define FCPPT_PP_DETAIL_POP_WARNING \
	FCPPT_PP_PRAGMA(warning(pop))
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/preprocessor/pragma.h>
#	define FCPPT_PP_DETAIL_POP_WARNING \
	FCPPT_PP_PRAGMA(GCC diagnostic pop)
#else
	#define FCPPT_PP_DETAIL_POP_WARNING
#endif

#endif
