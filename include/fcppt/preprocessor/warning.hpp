//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/message.hpp>


/**
\brief Prints a warning compiler message

\ingroup fcpptpreprocessor

Prints the compiler message <code>"warning: " message</code>. Note, that this
is just a normal message and might not be interpreted by the compiler, IDE,
etc. as a real warning.

\param message The message should be a narrow string literal

\see FCPPT_PP_MESSAGE
*/
#define FCPPT_PP_WARNING(\
	message\
)\
FCPPT_PP_MESSAGE(\
	"warning: " message\
)

#endif
