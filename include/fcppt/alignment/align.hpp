//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_ALIGN_HPP_INCLUDED
#define FCPPT_ALIGNMENT_ALIGN_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#define FCPPT_ALIGNMENT_ALIGN_IMPL(x) __declspec(align(x))
#elif defined(FCPPT_CONFIG_GCC_COMPILER) || defined(FCPPT_CONFIG_ICC_COMPILER)
#define FCPPT_ALIGNMENT_ALIGN_IMPL(x) __attribute__((__aligned__((x))))
#else
#error "Don't know how to align types!"
#endif

/**
\brief Specifies the alignment for a declaration

This macro must be placed after the type and before the declarator.
It will specify \a alignment for the declaration.

\ingroup fcpptalignment
*/
#define FCPPT_ALIGNMENT_ALIGN(\
	alignment\
)\
FCPPT_ALIGNMENT_ALIGN_IMPL(\
	alignment\
)

#endif
