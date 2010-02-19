//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_FIXME_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_FIXME_HPP_INCLUDED

#include <fcppt/preprocessor/message.hpp>

/// Prints the compiler message "FIXME: " @a x
#define FCPPT_PP_FIXME(x) FCPPT_PP_MESSAGE("FIXME: " x)

#endif
