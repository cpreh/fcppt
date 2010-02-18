//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/config.h>

/// Pretty printing macro for the current function
/** May return an empty string if there is no support for function names
*/
#ifdef FCPPT_HAS_PRETTY_FUNCTION
#ifdef FCPPT_NARROW_STRING
#define FCPPT_PP_FUNCTION __PRETTY_FUNCTION__
#else
#define FCPPT_PP_DETAIL_WIDEN(s) FCPPT_TEXT(s)
#define FCPPT_PP_FILE FCPPT_PP_DETAIL_WIDEN(__PRETTY_FUNCTION__)
#endif
#else
#define FCPPT_PP_FUNCTION FCPPT_TEXT("")
#endif

#endif
