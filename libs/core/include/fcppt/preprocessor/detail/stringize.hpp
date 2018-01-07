//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_STRINGIZE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_STRINGIZE_HPP_INCLUDED

#include <fcppt/public_config.hpp>


#if defined(FCPPT_NARROW_STRING)
#define FCPPT_PP_DETAIL_STRINGIZE(s) #s
#else
#define FCPPT_PP_DETAIL_STRINGIZE(s) L ## #s
#endif

#endif
