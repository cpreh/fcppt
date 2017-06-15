//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_POP_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_POP_WARNING_H_INCLUDED

#include <fcppt/preprocessor/detail/pop_warning.h>


/**
\brief Pops the current warning stack

\ingroup fcpptpreprocessor

Pops the stack of the current warning settings so that changes made since the
last FCPPT_PP_PUSH_WARNING will be undone.

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_POP_WARNING \
FCPPT_PP_DETAIL_POP_WARNING


#endif
