//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_STRINGIZE_NARROW_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_STRINGIZE_NARROW_HPP_INCLUDED

#define FCPPT_PP_DETAIL_STRINGIZE_NARROW(x) #x

/**
\brief Creates a string from its macro argument.

\ingroup fcpptpreprocessor

\param string The argument to stringize.
*/
#define FCPPT_PP_STRINGIZE_NARROW(string) FCPPT_PP_DETAIL_STRINGIZE_NARROW(string)

#endif
