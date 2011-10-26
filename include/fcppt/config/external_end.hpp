//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED
#define FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED

#if !defined(FCPPT_CONFIG_INSIDE_EXTERNAL)
#error "#include <fcppt/config/external_end.hpp> without prior begin!"
#endif

#undef FCPPT_CONFIG_INSIDE_EXTERNAL

#include <fcppt/preprocessor/pop_warning.hpp>
FCPPT_PP_POP_WARNING

#endif

#undef FCPPT_CONFIG_EXTERNAL_END_HPP_INCLUDED
