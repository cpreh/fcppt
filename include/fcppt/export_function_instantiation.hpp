//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXPORT_FUNCTION_INSTANTIATION_HPP_INCLUDED
#define FCPPT_EXPORT_FUNCTION_INSTANTIATION_HPP_INCLUDED

#include <fcppt/export_symbol.hpp>

/**
\brief Tells that an explicit function instantiation should be exported

\ingroup fcpptexport

This macro marks an explicitly instantiated template function to be exported,
so it can be used by other libraries or programs.

\see \ref exports_library
*/
#define FCPPT_EXPORT_FUNCTION_INSTANTIATION FCPPT_EXPORT_SYMBOL

#endif
