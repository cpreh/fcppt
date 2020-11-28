//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_STD_HASH_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_STD_HASH_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/strong_typedef_hash_impl.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>

namespace std
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmismatched-tags)

template <typename Type, typename Alias>
struct hash<fcppt::strong_typedef<Type, Alias>>
{
  using type = fcppt::strong_typedef<Type, Alias>;

  std::size_t operator()(type const &_value) const
  {
    return fcppt::strong_typedef_hash<type>()(_value);
  }
};

FCPPT_PP_POP_WARNING

}

#endif
