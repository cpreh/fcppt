//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_FILE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_FILE_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/config.hpp>

#ifdef FCPPT_NARROW_STRING
#define FCPPT_PP_DETAIL_FILE __FILE__
#else
#define FCPPT_PP_DETAIL_WIDEN(s) FCPPT_TEXT(s)
#define FCPPT_PP_DETAIL_FILE FCPPT_PP_DETAIL_WIDEN(__FILE__)
#endif

#endif
