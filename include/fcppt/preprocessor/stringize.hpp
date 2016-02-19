//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_STRINGIZE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/stringize.hpp>

/**
\brief Creates a string from its macro argument

\ingroup fcpptpreprocessor

Stringizes its macro argument so that it is suitable to use with fcppt::string.

\param string The argument to stringize
*/
#define FCPPT_PP_STRINGIZE(\
	string\
)\
FCPPT_PP_DETAIL_STRINGIZE(\
	string\
)

#endif
