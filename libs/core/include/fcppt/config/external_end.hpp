//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED

#include <fcppt/detail/check_cpp.hpp>

#if !defined(FCPPT_CONFIG_INSIDE_EXTERNAL_HPP)
#error "#include <fcppt/config/external_end.hpp> without prior begin!"
#endif

#undef FCPPT_CONFIG_INSIDE_EXTERNAL_HPP

#include <fcppt/preprocessor/pop_warning.hpp>
FCPPT_PP_POP_WARNING

#endif

#include <fcppt/config/external_end.h>

#undef FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED
