//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED
#define FCPPT_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_EXPORT_CLASS_INSTANTIATION_IMPL
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	include <fcppt/export_symbol.hpp>
#	define FCPPT_EXPORT_CLASS_INSTANTIATION_IMPL FCPPT_EXPORT_SYMBOL
#else
#	error "Don't know what FCPPT_EXPORT_CLASS_INSTANTIATION should be"
#endif


/**
\brief Tells that an explicit class instantiation should be exported

\ingroup fcpptexport

This macro marks an explicitly instantiated template class to be exported, so
it can be used by other libraries or programs.

\see \ref exports_library
*/
#define FCPPT_EXPORT_CLASS_INSTANTIATION FCPPT_EXPORT_CLASS_INSTANTIATION_IMPL

#endif
