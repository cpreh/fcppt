//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_ENUM_RANGE_START_END_HPP_INCLUDED
#define FCPPT_MPL_LIST_ENUM_RANGE_START_END_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/cast/int_to_enum_fun.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/type_traits/enum_constant_concept.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template <typename Start, typename Max>
struct enum_range_start_end;

template <typename Enum, Enum Start, Enum Max>
struct enum_range_start_end<std::integral_constant<Enum, Start>, std::integral_constant<Enum, Max>>
{
  using underlying = std::underlying_type_t<Enum>;
  using type = fcppt::mpl::list::map<
      fcppt::mpl::list::interval<
          std::integral_constant<underlying, fcppt::cast::enum_to_underlying(Start)>,
          std::integral_constant<
              underlying,
              fcppt::cast::enum_to_underlying(Max) +
                  fcppt::literal<std::underlying_type_t<Enum>>(1)>>,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<fcppt::type_traits::integral_cast>,
          fcppt::mpl::constant<Enum>,
          fcppt::mpl::constant<fcppt::cast::int_to_enum_fun>,
          fcppt::mpl::arg<1>>>;
};
}
/**
\brief An mpl::list::object over enums from a minimum to a maximum.

\ingroup fcpptenum

Let <code>Start = std::integral_constant<Enum,S></code> and <code>Max = std::integral_constant<Enum,M></code>.
Then the result is
\code
mpl::list::object<std::integral_constant<Enum,S>, std::integral_constant<Enum,S + 1>, ..., std::integral_constant<Enum,M>>
\endcode
*/
template <
    fcppt::type_traits::enum_constant_concept Start,
    fcppt::type_traits::enum_constant_concept Max>
requires std::is_same_v<fcppt::type_traits::value_type<Start>, fcppt::type_traits::value_type<Max>>
using enum_range_start_end =
    typename fcppt::mpl::list::detail::enum_range_start_end<Start, Max>::type;
}

#endif
