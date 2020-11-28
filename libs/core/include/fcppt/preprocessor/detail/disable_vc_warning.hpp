//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PREPROCESSOR_DETAIL_DISABLE_VC_WARNING_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_DISABLE_VC_WARNING_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>

#if defined(FCPPT_CONFIG_MSVC_COMPILER)
#include <fcppt/preprocessor/pragma.hpp>
#define FCPPT_PP_DETAIL_DISABLE_VC_WARNING(number) FCPPT_PP_PRAGMA(warning(disable : number))
#else
#define FCPPT_PP_DETAIL_DISABLE_VC_WARNING(number)
#endif

#endif
