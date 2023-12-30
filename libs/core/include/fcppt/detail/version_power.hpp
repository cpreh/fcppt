//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_VERSION_POWER_HPP_INCLUDED
#define FCPPT_DETAIL_VERSION_POWER_HPP_INCLUDED

#include <fcppt/version_int.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::detail
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-const-variable)

constexpr fcppt::version_int const version_power = 1000U;

FCPPT_PP_POP_WARNING

}

#endif
