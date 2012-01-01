//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_GCC_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_GCC_WARNING_HPP_INCLUDED

#include <fcppt/config.hpp>
#include <fcppt/preprocessor/pragma.hpp>


/// Disables a given gcc warning (does nothing on other compilers)
#if defined(FCPPT_HAVE_GCC_DIAGNOSTIC)
	#define FCPPT_PP_DISABLE_GCC_WARNING(id) \
	FCPPT_PP_PRAGMA(GCC diagnostic ignored #id)
#else
	#define FCPPT_PP_DISABLE_GCC_WARNING(id)
#endif

#endif
