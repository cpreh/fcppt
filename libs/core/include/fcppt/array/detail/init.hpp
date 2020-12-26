//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_ARRAY_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array::detail
{
template <typename Array, typename Function, std::size_t... Ints>
inline Array init(std::index_sequence<Ints...>, Function const &_function)
{
  return Array{_function(std::integral_constant<std::size_t, Ints>{})...};
} // NOLINT(clang-analyzer-cplusplus.NewDeleteLeaks)

}

#endif
