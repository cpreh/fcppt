//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_VC_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_VC_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/detail/disable_vc_warning.hpp>


/**
\brief Disables a given VC++ warning (does nothing on other compilers)

\ingroup fcpptpreprocessor

Disables the VC++ warning denoted by \a warning_number

\param warning_number The warning number to disable

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_DISABLE_VC_WARNING(\
	warning_number\
)\
FCPPT_PP_DETAIL_DISABLE_VC_WARNING(\
	warning_number\
)

#endif
