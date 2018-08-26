//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED

#include <fcppt/preprocessor/detail/function.hpp>

/**
\brief Pretty prints the current function name

\ingroup fcpptpreprocessor

If support for pretty function printing is available, this macro will expand to
the name of the current function, either as a literal or as some other rvalue,
depending on the compiler. The type of the function name is suitable to use
with fcppt::string.

If there is no support for function printing, then this macro will always
expand to an empty literal.
*/
#define FCPPT_PP_FUNCTION FCPPT_PP_DETAIL_FUNCTION

#endif
