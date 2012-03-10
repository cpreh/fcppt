//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_GCC_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_GCC_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/detail/disable_gcc_warning.hpp>


/**
\brief Disables a given gcc warning (does nothing on other compilers)

Disables the gcc warning denoted by \a warning_name

\param warning_name The full command line option of the warning to disable

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_DISABLE_GCC_WARNING(\
	warning_name\
)\
FCPPT_PP_DETAIL_DISABLE_GCC_WARNING(\
	warning_name\
)

#endif
