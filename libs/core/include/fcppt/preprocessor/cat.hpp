//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_CAT_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_CAT_HPP_INCLUDED

#define FCPPT_PP_DETAIL_CAT(x,y) x ## y

/**
\brief Concatenates two macros after expanding.

\ingroup fcpptpreprocessor
*/
#define FCPPT_PP_CAT(x,y) FCPPT_PP_DETAIL_CAT(x, y)

#endif
