//          Copyright Carl Philipp Reh 2009 - 2012.
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

/**
\brief Tells that a classes's vtable should be exported

\ingroup fcpptexport

This macro marks a classes's vtable to be exported, so it can be shared across
dynamic libraries. There are several cases in which this is necessary:
<ol>

<li>The class is thrown as an exception and caught by another library.</li>

<li>The class has virtual methods that will be called directly from another
library.</li>

</ol>

It is not necessary to specify whether the class is currently exported or
imported.

\code
class FCPPT_CLASS_SYMBOL my_exception
{
};

class FCPPT_CLASS_SYMBOL my_base
{
	virtual
	void
	do_something() = 0;
};
\endcode

\see \ref exports_vtable
*/
#define FCPPT_CLASS_SYMBOL FCPPT_CLASS_SYMBOL_IMPL

#endif
