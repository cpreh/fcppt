//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PUSH_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PUSH_WARNING_HPP_INCLUDED

#include <fcppt/config.hpp>
#include <fcppt/config/compiler.hpp>


/// Push the warning level (only supported on VC++ for now)
#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	include <fcppt/preprocessor/pragma.hpp>
#	define FCPPT_PP_PUSH_WARNING \
	FCPPT_PP_PRAGMA(warning(push))
#elif defined(FCPPT_HAVE_GCC_DIAGNOSTIC)
#	include <fcppt/preprocessor/pragma.hpp>
#	define FCPPT_PP_PUSH_WARNING \
	FCPPT_PP_PRAGMA(GCC diagnostic push)
#else
	#define FCPPT_PP_PUSH_WARNING
#endif

#endif
