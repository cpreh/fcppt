//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_BEGIN_H_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_BEGIN_H_INCLUDED

#if defined(FCPPT_CONFIG_INSIDE_EXTERNAL_H)
#error "Missing #include <fcppt/config/external_end.h>"
#endif

#include <fcppt/config/compiler.h>
#include <fcppt/preprocessor/push_warning.h>
FCPPT_PP_PUSH_WARNING

#if defined(FCPPT_CONFIG_GCC_COMPILER)

#include <fcppt/config/gcc_version_at_least.h>
#include <fcppt/preprocessor/disable_gcc_warning.h>

#if defined(FCPPT_CONFIG_CLANG_COMPILER)

#include <fcppt/config/clang_version_at_least.h>

FCPPT_PP_DISABLE_GCC_WARNING(-Wtautological-compare)
FCPPT_PP_DISABLE_GCC_WARNING(-Wconditional-uninitialized)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdocumentation)
FCPPT_PP_DISABLE_GCC_WARNING(-Wextra-semi)
FCPPT_PP_DISABLE_GCC_WARNING(-Wimplicit-fallthrough)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnewline-eof)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-local-typedef)

#if FCPPT_CONFIG_CLANG_VERSION_AT_LEAST(3, 9)
FCPPT_PP_DISABLE_GCC_WARNING(-Wexpansion-to-defined)
#endif

#else

FCPPT_PP_DISABLE_GCC_WARNING(-Wdouble-promotion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-conversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wlogical-op)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmaybe-uninitialized)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-local-typedefs)

#endif

FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcast-align)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcast-qual)
FCPPT_PP_DISABLE_GCC_WARNING(-Wcomment)
FCPPT_PP_DISABLE_GCC_WARNING(-Wconversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wdeprecated-declarations)
FCPPT_PP_DISABLE_GCC_WARNING(-Wfloat-equal)
FCPPT_PP_DISABLE_GCC_WARNING(-Wignored-qualifiers)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-field-initializers)
FCPPT_PP_DISABLE_GCC_WARNING(-Wredundant-decls)
FCPPT_PP_DISABLE_GCC_WARNING(-Wshadow)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-compare)
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-conversion)
FCPPT_PP_DISABLE_GCC_WARNING(-Wstrict-aliasing)
FCPPT_PP_DISABLE_GCC_WARNING(-Wtype-limits)
FCPPT_PP_DISABLE_GCC_WARNING(-Wundef)
FCPPT_PP_DISABLE_GCC_WARNING(-Wuninitialized)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunknown-pragmas)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-function)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-parameter)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-variable)

#if !FCPPT_CONFIG_GCC_VERSION_AT_LEAST(6, 0)
FCPPT_PP_DISABLE_GCC_WARNING(-Wunreachable-code)
#endif

#endif

#define FCPPT_CONFIG_INSIDE_EXTERNAL_H

#endif

#undef FCPPT_CONFIG_EXTERNAL_BEGIN_H_INCLUDED
