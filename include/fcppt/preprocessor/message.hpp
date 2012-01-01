//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_MESSAGE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_MESSAGE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/message.hpp>

/// Prints a compiler message
/**
 * This macro might be unsupported on old platforms and will print nothing.
*/
#define FCPPT_PP_MESSAGE(x) FCPPT_PP_DETAIL_MESSAGE(x)

#endif
