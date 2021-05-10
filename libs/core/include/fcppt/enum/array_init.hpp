//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/array/init.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Constructs an array by calling a function with static enumerators.

\ingroup fcpptenum

Constructs an enum array of type \a Array by calling
<code>_function(std::integral_constant<Array::enum_type,E>)</code> for every
enumerator <code>E</code>.

\tparam Array Must be an #fcppt::enum_::array.

\tparam Function Must be a function callable as <code>Array::value_type
(std::integral_constant<Array::enum_type,E>)</code>.

\see fcppt::array::init
*/
template <typename Array, typename Function>
inline Array array_init(Function const &_function)
{
  return Array{
      typename Array::from_internal{},
      fcppt::array::init<typename Array::internal>(
          [&_function]<std::size_t Index>(std::integral_constant<std::size_t, Index>)
          {
            return _function(fcppt::type_traits::integral_cast<
                             typename Array::enum_type,
                             fcppt::cast::int_to_enum_fun,
                             std::integral_constant<std::size_t, Index>>{});
          })};
}
}
}

#endif
