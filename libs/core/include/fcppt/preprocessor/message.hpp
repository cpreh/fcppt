//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_MESSAGE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_MESSAGE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/message.hpp>


/**
\brief Prints a compiler message

\ingroup fcpptpreprocessor

Intructs the compiler to print \a message. If there is no support for compiler
messages, nothing will happen.

\param message The message should be a narrow string literal
*/
#define FCPPT_PP_MESSAGE(\
	message\
)\
FCPPT_PP_DETAIL_MESSAGE(\
	message\
)

#endif
