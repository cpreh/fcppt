//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_MAKE_TUPLE_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_MAKE_TUPLE_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Type>
inline std::remove_cvref_t<Type> make_tuple(Type &&_value)
  requires(fcppt::tuple::is_object<std::remove_cvref_t<Type>>::value)
{
  return std::forward<Type>(_value);
}

template <typename Type>
fcppt::tuple::object<std::remove_cvref_t<Type>> make_tuple(Type &&_value)
  requires(fcppt::not_(fcppt::tuple::is_object<std::remove_cvref_t<Type>>::value))
{
  return fcppt::tuple::make(std::forward<Type>(_value));
}
}

#endif
