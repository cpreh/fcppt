//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_CONST_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_CONST_HPP_INCLUDED

#include <fcppt/config.hpp>

#ifdef FCPPT_HAVE_CONST_ATTRIBUTE
#define FCPPT_PP_CONST __attribute__((const))
#else
#define FCPPT_PP_CONST
#endif

#endif

