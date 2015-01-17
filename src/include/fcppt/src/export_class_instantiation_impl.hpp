//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_EXPORT_CLASS_INSTANTIATION_IMPL_HPP_INCLUDED
#define FCPPT_SRC_EXPORT_CLASS_INSTANTIATION_IMPL_HPP_INCLUDED

#if defined(FCPPT_STATIC_LINK)
#	define FCPPT_EXPORT_CLASS_INSTANTIATION_IMPL
#else
#	include <fcppt/symbol/export_class_instantiation.hpp>
#	define FCPPT_EXPORT_CLASS_INSTANTIATION_IMPL FCPPT_SYMBOL_EXPORT_CLASS_INSTANTIATION
#endif

#endif
