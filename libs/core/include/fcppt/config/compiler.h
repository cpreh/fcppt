//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONFIG_COMPILER_H_INCLUDED
#define FCPPT_CONFIG_COMPILER_H_INCLUDED

#ifdef _MSC_VER
#define FCPPT_CONFIG_MSVC_COMPILER
#elifdef __GNUC__
#define FCPPT_CONFIG_GCC_COMPILER
#if !defined(__clang__) && !defined(__APPLE_CC__)
#define FCPPT_CONFIG_GNU_GCC_COMPILER
#endif
#endif

// clang emulates gcc, so FCPPT_CONFIG_GCC_COMPILER will also be defined
#ifdef __clang__
#define FCPPT_CONFIG_CLANG_COMPILER
#ifdef __APPLE_CC__
#define FCPPT_CONFIG_APPLE_CLANG_COMPILER
#endif
#endif

#endif
