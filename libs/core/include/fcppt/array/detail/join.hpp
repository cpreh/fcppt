//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_DETAIL_JOIN_HPP_INCLUDED
#define FCPPT_ARRAY_DETAIL_JOIN_HPP_INCLUDED

#include <fcppt/array/append.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array::detail
{
template <typename Array1>
inline auto join(Array1 &&_array1)
{
  return std::forward<Array1>(_array1);
}

template <typename Array1, typename Array2, typename... Arrays>
inline auto join(Array1 &&_array1, Array2 &&_array2, Arrays &&..._arrays)
{
  return fcppt::array::detail::join(
      fcppt::array::append(std::forward<Array1>(_array1), std::forward<Array2>(_array2)),
      std::forward<Arrays>(_arrays)...);
}

}

#endif
