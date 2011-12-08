//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TR1_DETAIL_MAKE_HEADER_HPP_INCLUDED
#define FCPPT_TR1_DETAIL_MAKE_HEADER_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#	define FCPPT_TR1_DETAIL_MAKE_HEADER(name) <name>
#elif defined(FCPPT_CONFIG_GCC_COMPILER)
#	define FCPPT_TR1_DETAIL_MAKE_HEADER(name) <tr1/name>
#else
#	error "Don't know where the tr1 headers are"
#endif

#endif
