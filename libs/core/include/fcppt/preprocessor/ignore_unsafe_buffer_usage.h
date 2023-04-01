//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_IGNORE_UNSAFE_BUFFER_USAGE_H_INCLUDED
#define FCPPT_PREPROCESSOR_IGNORE_UNSAFE_BUFFER_USAGE_H_INCLUDED

#include <fcppt/config/clang_version_at_least.h>
#include <fcppt/preprocessor/disable_clang_warning.h>

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(16, 0)
#define FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE FCPPT_PP_DISABLE_CLANG_WARNING(-Wunsafe-buffer-usage)
#else
#define FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE
#endif

#endif
