//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_DETAIL_MAKE_INTERNAL_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_DETAIL_MAKE_INTERNAL_TYPE_HPP_INCLUDED

#include <fcppt/cast/size_fun.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/greater.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/front.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/push_back.hpp>
#include <fcppt/mpl/list/remove_if.hpp>
#include <fcppt/type_traits/integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::bitfield::detail
{

template <typename Enum>
struct make_internal_type_impl
{
  using int_types =
      fcppt::mpl::list::object<std::uint_least8_t, std::uint_least16_t, std::uint_least32_t>;

  template <typename Type>
  using num_bits = fcppt::type_traits::integral_cast<
      fcppt::enum_::size_type<Enum>,
      fcppt::cast::size_fun,
      std::integral_constant<int, std::numeric_limits<Type>::digits>>;

  using possible_types = fcppt::mpl::list::remove_if<
      int_types,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<fcppt::mpl::greater>,
          fcppt::mpl::constant<fcppt::enum_::size<Enum>>,
          fcppt::mpl::bind<fcppt::mpl::lambda<num_bits>, fcppt::mpl::arg<1>>>>;

  using type = fcppt::mpl::list::front<fcppt::mpl::list::push_back<possible_types, std::uint_least64_t>>;
};

template <typename Enum>
using make_internal_type =
    fcppt::container::bitfield::detail::make_internal_type_impl<Enum>::type;
}

#endif
