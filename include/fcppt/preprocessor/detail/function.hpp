//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED

#include <fcppt/config.hpp>

#ifdef FCPPT_HAS_PRETTY_FUNCTION
#include <fcppt/from_std_string.hpp>
#define FCPPT_PP_DETAIL_FUNCTION ::fcppt::from_std_string(__PRETTY_FUNCTION__)
#else
#include <fcppt/text.hpp>
#define FCPPT_PP_DETAIL_FUNCTION FCPPT_TEXT("")
#endif

#endif
