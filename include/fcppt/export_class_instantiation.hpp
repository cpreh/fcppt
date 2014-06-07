//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED
#define FCPPT_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED

#include <fcppt/detail/export_class_instantiation.hpp>


/**
\brief Tells that an explicit class instantiation should be exported

\ingroup fcpptexport

This macro marks an explicitly instantiated template class to be exported, so
it can be used by other libraries or programs.

\see \ref exports_library
*/
#define FCPPT_EXPORT_CLASS_INSTANTIATION FCPPT_DETAIL_EXPORT_CLASS_INSTANTIATION

#endif
