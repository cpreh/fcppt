//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CLASS_SYMBOL_HPP_INCLUDED
#define FCPPT_CLASS_SYMBOL_HPP_INCLUDED

#if defined(_MSC_VER)
#	define FCPPT_CLASS_SYMBOL
#elif defined(__GNUC__)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_CLASS_SYMBOL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_CLASS_SYMBOL should be"
#endif

#endif
