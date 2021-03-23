//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_TO_STATIC_HPP_INCLUDED
#define FCPPT_ENUM_TO_STATIC_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/runtime_index.hpp>
#include <fcppt/use.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief Converts a runtime enum value into a compile time one, passing it to a
function

\ingroup fcpptenum
*/
template <typename Enum, typename Function>
inline decltype(auto) to_static(Enum const _enum, Function const &_function)
{
  static_assert(std::is_enum_v<Enum>, "runtime_enum can only be used on enumeration types");

  using int_type = fcppt::enum_::size_type<Enum>;

  return fcppt::runtime_index<fcppt::enum_::size<Enum>>(
      fcppt::cast::enum_to_int<int_type>(_enum),
      [&_function](auto const _fcppt_index) -> decltype(auto) {
        FCPPT_USE(_fcppt_index);

        return _function(
            fcppt::type_traits::
                integral_cast<Enum, fcppt::cast::static_cast_fun, decltype(_fcppt_index)>{});
      },
      &fcppt::absurd<decltype(_function(fcppt::enum_::max_value<Enum>{}))>);
}

}
}

#endif
