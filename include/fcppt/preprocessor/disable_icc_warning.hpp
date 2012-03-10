//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_ICC_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_ICC_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/detail/disable_icc_warning.hpp>


/**
\brief Disables a given icc warning (does nothing on other compilers)

Disables the icc warning denoted by \a warning_number

\param warning_name The warning number to disable

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_DISABLE_ICC_WARNING(\
	warning_number\
)\
FCPPT_PP_DETAIL_DISABLE_ICC_WARNING(\
	warning_number\
)

#endif
