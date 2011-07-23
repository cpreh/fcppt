//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_FUNCTION_HPP_INCLUDED

#include <fcppt/config.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>

#if defined(FCPPT_HAVE_GCC_PRETTY_FUNCTION)
#define FCPPT_PP_DETAIL_FUNCTION fcppt::from_std_string(__PRETTY_FUNCTION__)
#elif defined(_MSC_VER)
#define FCPPT_PP_DETAIL_FUNCTION fcppt::from_std_string(__FUNCSIG__)
#else
#define FCPPT_PP_DETAIL_FUNCTION FCPPT_TEXT("")
#endif

#endif
