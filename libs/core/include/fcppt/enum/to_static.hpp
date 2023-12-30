//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STATIC_HPP_INCLUDED
#define FCPPT_ENUM_TO_STATIC_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/runtime_index.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Converts a runtime enum value into a compile time one, passing it to a
function

\ingroup fcpptenum

\tparam Function A function callable as <code>R (std::integal_constant<Enum,E>)</code>,
where <code>R</code> is the result type.
*/
template <
    typename Enum,
    typename Function,
    typename = std::enable_if_t<fcppt::enum_::is_object<Enum>::value>>
inline decltype(auto) to_static(Enum const _enum, Function const &_function)
{
  using int_type = fcppt::enum_::size_type<Enum>;

  return fcppt::runtime_index<fcppt::enum_::size<Enum>>(
      fcppt::cast::enum_to_int<int_type>(_enum),
      [&_function]<int_type Index>(std::integral_constant<int_type, Index>) -> decltype(auto)
      {
        return _function(fcppt::type_traits::integral_cast<
                         Enum,
                         fcppt::cast::static_cast_fun,
                         std::integral_constant<int_type, Index>>{});
      },
      &fcppt::absurd<decltype(_function(fcppt::enum_::max_value<Enum>{}))>);
}

}

#endif
