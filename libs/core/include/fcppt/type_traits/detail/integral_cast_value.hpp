//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_DETAIL_INTEGRAL_CAST_VALUE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_INTEGRAL_CAST_VALUE_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>

namespace fcppt
{
namespace type_traits
{
namespace detail
{
template <typename IntegralType, typename Conv, typename Integral>
struct integral_cast_value
{
  static constexpr IntegralType const value{
      fcppt::cast::apply<Conv, IntegralType>(Integral::value)};
};

}
}
}

#endif
