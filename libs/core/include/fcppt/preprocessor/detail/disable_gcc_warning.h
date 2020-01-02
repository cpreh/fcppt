//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_DISABLE_GCC_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_DISABLE_GCC_WARNING_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/preprocessor/pragma.h>
#	define FCPPT_PP_DETAIL_DISABLE_GCC_WARNING(id) \
	FCPPT_PP_PRAGMA(GCC diagnostic ignored #id)
#else
#	define FCPPT_PP_DETAIL_DISABLE_GCC_WARNING(id)
#endif

#endif
