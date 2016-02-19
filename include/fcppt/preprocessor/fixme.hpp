//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FIXME_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FIXME_HPP_INCLUDED

#include <fcppt/preprocessor/message.hpp>


/**
\brief Prints a FIXME compiler message

\ingroup fcpptpreprocessor

Prints the compiler message <code>"FIXME: " message</code>.

\param message The message should be a narrow string literal

\see FCPPT_PP_MESSAGE
*/
#define FCPPT_PP_FIXME(\
	message\
)\
FCPPT_PP_MESSAGE(\
	"FIXME: " message\
)

#endif
