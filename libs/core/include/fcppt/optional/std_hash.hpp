//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_STD_HASH_HPP_INCLUDED
#define FCPPT_OPTIONAL_STD_HASH_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <optional> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

namespace std
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmismatched-tags)

template <typename T>
struct hash<fcppt::optional::object<T>>
{
  using type = fcppt::optional::object<T>;

  std::size_t operator()(type const &_value) const
  {
    return std::hash<typename type::std_type>{}(_value.impl());
  }
};

FCPPT_PP_POP_WARNING

}

#endif
