//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MAKE_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAKE_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gnu_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Wraps a value into an optional.

\ingroup fcpptoptional
*/
template <typename Type>
[[nodiscard]] inline fcppt::optional::object<std::remove_cvref_t<Type>> make(Type &&_value)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GNU_GCC_WARNING(-Wmaybe-uninitialized)

  return fcppt::optional::object<std::remove_cvref_t<Type>>{std::forward<Type>(_value)};

  FCPPT_PP_POP_WARNING
}
}

#endif
