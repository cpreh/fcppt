//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_GNU_GCC_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_GNU_GCC_WARNING_H_INCLUDED

#include <fcppt/preprocessor/detail/disable_gnu_gcc_warning.h>


/**
\brief Disables a given gcc (which does not include clang here) warning (does nothing on other compilers)

\ingroup fcpptpreprocessor

Disables the gcc (not clang) warning denoted by \a warning_name

\param warning_name The full command line option of the warning to disable

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_DISABLE_GNU_GCC_WARNING(\
	warning_name\
)\
FCPPT_PP_DETAIL_DISABLE_GNU_GCC_WARNING(\
	warning_name\
)

#endif
