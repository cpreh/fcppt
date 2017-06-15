//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED
#define FCPPT_IMPL_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED

#if defined(FCPPT_STATIC_LINK)
#	define FCPPT_IMPL_EXPORT_CLASS_INSTANTIATION
#else
#	include <fcppt/symbol/export_class_instantiation.hpp>
#	define FCPPT_IMPL_EXPORT_CLASS_INSTANTIATION FCPPT_SYMBOL_EXPORT_CLASS_INSTANTIATION
#endif

#endif
