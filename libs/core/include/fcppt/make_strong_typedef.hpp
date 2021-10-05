//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MAKE_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_MAKE_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Creates a new strong typedef given a tag and a value.
\ingroup fcpptstrongtypedef
*/
template <typename Tag, typename Type>
[[nodiscard]] inline fcppt::strong_typedef<std::remove_cvref_t<Type>, Tag>
make_strong_typedef(Type &&_value)
{
  return fcppt::strong_typedef<std::remove_cvref_t<Type>, Tag>{std::forward<Type>(_value)};
}
}

#endif
