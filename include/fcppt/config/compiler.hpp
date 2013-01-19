//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_COMPILER_HPP_INCLUDED
#define FCPPT_CONFIG_COMPILER_HPP_INCLUDED

#if defined(_MSC_VER)
#define FCPPT_CONFIG_MSVC_COMPILER
// ICC emulates gcc to some extent, but we want to take a different code path for it
#elif defined(__ICC)
#define FCPPT_CONFIG_ICC_COMPILER
#elif defined(__GNUC__)
#define FCPPT_CONFIG_GCC_COMPILER
#endif

// clang emulates gcc, so FCPPT_CONFIG_GCC_COMPILER will also be defined
#if defined(__clang__)
#define FCPPT_CONFIG_CLANG_COMPILER
#endif

#endif
