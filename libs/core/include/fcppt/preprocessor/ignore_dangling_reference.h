//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_IGNORE_DANGLING_REFERENCE_H_INCLUDED
#define FCPPT_PREPROCESSOR_IGNORE_DANGLING_REFERENCE_H_INCLUDED

#include <fcppt/config/gcc_version_at_least.h>
#include <fcppt/preprocessor/disable_gcc_warning.h>

#if FCPPT_CONFIG_GCC_VERSION_AT_LEAST(13, 0)
#define FCPPT_PP_IGNORE_DANGLING_REFERENCE FCPPT_PP_DISABLE_GCC_WARNING(-Wdangling-reference)
#else
#define FCPPT_PP_IGNORE_DANGLING_REFERENCE
#endif

#endif
