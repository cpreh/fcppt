//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXPORT_SYMBOL_HPP_INCLUDED
#define FCPPT_EXPORT_SYMBOL_HPP_INCLUDED

/**
 * @brief Marks a symbol to be visible in dynamic libraries.
 *
 * FCPPT_EXPORT_SYMBOL may be used to override the default visibility.
*/
#if defined(_MSC_VER)
#	define FCPPT_EXPORT_SYMBOL __declspec(dllexport)
#elif defined(__GNUC__)
#	include <fcppt/config.hpp>
#	if defined(FCPPT_HAVE_GCC_VISIBILITY)
#		define FCPPT_EXPORT_SYMBOL __attribute__ ((visibility("default")))
#	else
#		define FCPPT_EXPORT_SYMBOL
#	endif
#else
#	error "Don't know what FCPPT_EXPORT_SYMBOL should be"
#endif

#endif
