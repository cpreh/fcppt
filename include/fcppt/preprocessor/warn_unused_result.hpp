//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_WARN_UNUSED_RESULT_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_WARN_UNUSED_RESULT_HPP_INCLUDED

#include <fcppt/config.hpp>

#ifdef FCPPT_HAVE_WARN_UNUSED_RESULT_ATTRIBUTE
#define FCPPT_PP_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#define FCPPT_PP_WARN_UNUSED_RESULT
#endif

#endif

