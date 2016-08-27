//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_COMPILER_H_INCLUDED
#define FCPPT_CONFIG_COMPILER_H_INCLUDED

#if defined(_MSC_VER)
#define FCPPT_CONFIG_MSVC_COMPILER
#elif defined(__GNUC__)
#define FCPPT_CONFIG_GCC_COMPILER
#endif

// clang emulates gcc, so FCPPT_CONFIG_GCC_COMPILER will also be defined
#if defined(__clang__)
#define FCPPT_CONFIG_CLANG_COMPILER
#if defined(__APPLE_CC__)
#define FCPPT_CONFIG_APPLE_CLANG_COMPILER
#endif
#endif

#endif
