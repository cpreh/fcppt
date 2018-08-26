//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FILE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FILE_HPP_INCLUDED

#include <fcppt/from_std_string.hpp>

/**
\brief Prints the current file name

\ingroup fcpptpreprocessor

It is equivalent to <code>__FILE__</code> except that it returns an rvalue that
is suitable to use with fcppt::string.
*/
#define FCPPT_PP_FILE \
fcppt::from_std_string(\
	__FILE__\
)

#endif
