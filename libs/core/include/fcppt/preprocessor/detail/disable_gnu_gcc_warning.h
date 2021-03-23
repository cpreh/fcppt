//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_DETAIL_DISABLE_GNU_GCC_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_DISABLE_GNU_GCC_WARNING_H_INCLUDED

#include <fcppt/config/compiler.h>


#if defined(FCPPT_CONFIG_GNU_GCC_COMPILER)
#	include <fcppt/preprocessor/detail/disable_gcc_warning.h>
#	define FCPPT_PP_DETAIL_DISABLE_GNU_GCC_WARNING(id) \
	FCPPT_PP_DETAIL_DISABLE_GCC_WARNING(id)
#else
#	define FCPPT_PP_DETAIL_DISABLE_GNU_GCC_WARNING(id)
#endif

#endif
