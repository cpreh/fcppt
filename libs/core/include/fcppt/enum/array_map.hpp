//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/map.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/enum/array_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{

/**
\brief Applies a function to every element of an enum_::array and returns an enum_::array of
the results.

\ingroup fcpptenum
*/
template <typename Array, typename Function>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
inline auto array_map(Array &&_source, Function const &_function)
    -> fcppt::enum_::array<
        typename std::remove_cvref_t<Array>::enum_type,
        decltype(_function(fcppt::move_if_rvalue<Array>(
            std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array>>>())))>
{
  using result_array = fcppt::enum_::array<
      typename std::remove_cvref_t<Array>::enum_type,
      decltype(_function(fcppt::move_if_rvalue<Array>(
          std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array>>>())))>;

  return result_array{
      typename result_array::from_internal{},
      fcppt::array::map(fcppt::move_if_rvalue<Array>(_source.impl()), _function)};
}
}

#endif
