//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_COMPILER_HPP_INCLUDED
#define FCPPT_CONFIG_COMPILER_HPP_INCLUDED

#if defined(_MSC_VER)
#define FCPPT_CONFIG_MSVC_COMPILER
#elif defined(__GNUC__)
#define FCPPT_CONFIG_GCC_COMPILER
#endif

#endif
