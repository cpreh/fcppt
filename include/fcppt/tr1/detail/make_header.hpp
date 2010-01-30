//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TR1_DETAIL_MAKE_HEADER_HPP_INCLUDED
#define FCPPT_TR1_DETAIL_MAKE_HEADER_HPP_INCLUDED

#if defined(_MSC_VER)
#	define FCPPT_TR1_DETAIL_MAKE_HEADER(name) <name>
#elif defined(__GNUC__)
#	define FCPPT_TR1_DETAIL_MAKE_HEADER(name) <tr1/name>
#else
#	error "Don't know where the tr1 headers are"
#endif

#endif
