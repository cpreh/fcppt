//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FUNCTION_HPP_INCLUDED

#include <fcppt/preprocessor/detail/function.hpp>

/// Pretty printing macro for the current function
/**
 * Note that the return type might be a variable or a literal!
 * @return May return an empty string if there is no support for function names
*/
#define FCPPT_PP_FUNCTION FCPPT_PP_DETAIL_FUNCTION

#endif
