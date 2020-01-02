//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SYMBOL_CLASS_HPP_INCLUDED
#define FCPPT_SYMBOL_CLASS_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_SYMBOL_CLASS_IMPL
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/symbol/export.hpp>
#	define FCPPT_SYMBOL_CLASS_IMPL FCPPT_SYMBOL_EXPORT
#else
#	error "Don't know what FCPPT_DETAIL_SYMBOL_CLASS should be"
#endif

/**
\brief Tells that a classes's vtable should be exported

\ingroup fcpptexport

This macro marks a classes's vtable to be exported, so it can be shared across
dynamic libraries. There are several cases in which this is necessary:
<ul>

<li>The class is thrown as an exception and caught by another library.</li>

<li>The class has virtual methods that will be called directly from another
library.</li>

</ul>

It is not necessary to specify whether the class is currently exported or
imported.

\code
class FCPPT_DETAIL_SYMBOL_CLASS my_exception
{
};

class FCPPT_DETAIL_SYMBOL_CLASS my_base
{
	virtual
	void
	do_something() = 0;
};
\endcode

\see \ref symbol_vtable
*/
#define FCPPT_SYMBOL_CLASS FCPPT_SYMBOL_CLASS_IMPL

#endif
