//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_NOTHING_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_NOTHING_IMPL_HPP_INCLUDED

#include <fcppt/optional/nothing_decl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)

template <typename T>
fcppt::optional::nothing::operator fcppt::optional::object<T>() const
{
  return fcppt::optional::object<T>{};
}

FCPPT_PP_POP_WARNING

#endif
