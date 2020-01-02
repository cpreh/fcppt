//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_PURE_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_PURE_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>


#if defined(FCPPT_CONFIG_GCC_COMPILER)
#define FCPPT_PP_PURE __attribute__((pure))
#else
#define FCPPT_PP_PURE
#endif

#endif
