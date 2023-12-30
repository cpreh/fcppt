//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_GET_HPP_INCLUDED
#define FCPPT_TUPLE_GET_HPP_INCLUDED

#include <fcppt/tuple/element.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <tuple> // IWYU pragma: keep
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt::tuple
{
/**
\brief Returns the I'th element of a nonconst tuple.
\ingroup fcppttuple
*/
template <std::size_t I, typename... Types, typename = std::enable_if_t<std::less<>{}(I,sizeof...(Types))>>
[[nodiscard]] constexpr inline fcppt::tuple::element<I, fcppt::tuple::object<Types...>> &
get(fcppt::tuple::object<Types...> &_value) noexcept
{
  return std::get<I>(_value.impl());
}

/**
\brief Returns the I'th element of a const tuple.
\ingroup fcppttuple
*/
template <std::size_t I, typename... Types, typename = std::enable_if_t<std::less<>{}(I,sizeof...(Types))>>
[[nodiscard]] constexpr inline fcppt::tuple::element<I, fcppt::tuple::object<Types...>> const &
get(fcppt::tuple::object<Types...> const &_value) noexcept
{
  return std::get<I>(_value.impl());
}

}

#endif
