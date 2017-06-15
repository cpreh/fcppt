//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_STRINGIZE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_STRINGIZE_HPP_INCLUDED

#include <fcppt/public_config.hpp>

#include <fcppt/config/external_begin.hpp>
#if defined(FCPPT_NARROW_STRING)
#include <boost/preprocessor/stringize.hpp>
#else
#include <boost/preprocessor/wstringize.hpp>
#endif
#include <fcppt/config/external_end.hpp>

#if defined(FCPPT_NARROW_STRING)
#define FCPPT_PP_DETAIL_STRINGIZE(s) BOOST_PP_STRINGIZE(s)
#else
#define FCPPT_PP_DETAIL_STRINGIZE(s) BOOST_PP_WSTRINGIZE(s)
#endif

#endif
