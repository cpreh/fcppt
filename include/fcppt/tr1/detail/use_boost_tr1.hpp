//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TR1_DETAIL_USE_BOOST_TR1_HPP_INCLUDED
#define FCPPT_TR1_DETAIL_USE_BOOST_TR1_HPP_INCLUDED

// clang currently doesn't have its own tr1 and doesn't work with gcc's
#if defined(__clang__)
#	define FCPPT_TR1_DETAIL_USE_BOOST_TR1
#endif

#endif
