//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_WARNING_HPP_INCLUDED

#include <fcppt/preprocessor/message.hpp>

/// Prints the compiler message "warning: " @a x
#define FCPPT_PP_WARNING(x) FCPPT_PP_MESSAGE("warning: " x)

#endif
