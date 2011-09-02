//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CLASS_SYMBOL_HPP_INCLUDED
#define FCPPT_CLASS_SYMBOL_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_CLASS_SYMBOL_IMPL
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_CLASS_SYMBOL_IMPL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_CLASS_SYMBOL should be"
#endif

/// Tells that a classes's vtable should be exported
/**
 * example: class FCPPT_CLASS_SYMBOL myclass {};
 * @remark This should be used when the vtable of a class is needed,
 * such as: 1) The class is thrown as an exception, 2) The class has virtual methods
*/
#define FCPPT_CLASS_SYMBOL FCPPT_CLASS_SYMBOL_IMPL

#endif
