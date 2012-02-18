//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_POP_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_POP_WARNING_HPP_INCLUDED

#include <fcppt/config.hpp>
#include <fcppt/config/compiler.hpp>


/// Pop the warning level
#if defined(FCPPT_CONFIG_MSVC_COMPILER) || defined(FCPPT_CONFIG_ICC_COMPILER)
#	include <fcppt/preprocessor/pragma.hpp>
#	define FCPPT_PP_POP_WARNING \
	FCPPT_PP_PRAGMA(warning(pop))
#elif defined(FCPPT_HAVE_GCC_DIAGNOSTIC)
#	include <fcppt/preprocessor/pragma.hpp>
#	define FCPPT_PP_POP_WARNING \
	FCPPT_PP_PRAGMA(GCC diagnostic pop)
#else
	#define FCPPT_PP_POP_WARNING
#endif

#endif
