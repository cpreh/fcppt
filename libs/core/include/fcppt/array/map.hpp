//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/get.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/is_object.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Applies a function to every element of an array and returns an array of
the results.

\ingroup fcpptarray

Calls <code>_function(element)</code> for every element of \a _source.

Example:

\snippet array.cpp array_map

\tparam Function Must be a function callable as <code>R (Array::value_type)</code>,
where <code>R</code> is the result type.
**/
template <typename Array, typename Function>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
inline auto map(Array &&_source, Function const &_function)
    -> fcppt::array::object<
        decltype(_function(fcppt::move_if_rvalue<Array>(
            std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array>>>()))),
        fcppt::array::size<std::remove_cvref_t<Array>>::value>
  requires(fcppt::array::is_object<std::remove_cvref_t<Array>>::value)
{
  using result_array = fcppt::array::object<
      decltype(_function(fcppt::move_if_rvalue<Array>(
          std::declval<fcppt::container::to_reference_type<std::remove_reference_t<Array>>>()))),
      fcppt::array::size<std::remove_cvref_t<Array>>::value>;

  return fcppt::array::init<result_array>(
      [&_source, &_function]<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      { return _function(fcppt::move_if_rvalue<Array>(fcppt::array::get<Index>(_source))); });
}
}

#endif
