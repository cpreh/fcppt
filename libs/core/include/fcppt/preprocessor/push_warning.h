//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_PUSH_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_PUSH_WARNING_H_INCLUDED

#include <fcppt/preprocessor/detail/push_warning.h>


/**
\brief Pushes the current warning stack

\ingroup fcpptpreprocessor

Pushes the stack of the current warning settings so that changes can be made
which can later be undone by FCPPT_PP_POP_WARNING

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_PUSH_WARNING \
FCPPT_PP_DETAIL_PUSH_WARNING

#endif
