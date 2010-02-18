//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED

#include <fcppt/config.h>

#ifdef FCPPT_NARROW_STRING
#include <boost/preprocessor/stringize.hpp>
#else
#include <boost/preprocessor/wstringize.hpp>
#endif

/// Stringizes a macro parameter used with BOOST_PP so that it is compatible with fcppt::string
#ifdef FCPPT_NARROW_STRING
#define FCPPT_PP_STRINGIZE(s) BOOST_PP_STRINGIZE(s)
#else
#define FCPPT_PP_STRINGIZE(s) BOOST_PP_WSTRINGIZE(s)
#endif

#endif
