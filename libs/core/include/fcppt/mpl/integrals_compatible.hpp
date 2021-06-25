//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_INTEGRALS_COMPATIBLE_HPP_INCLUDED
#define FCPPT_MPL_INTEGRALS_COMPATIBLE_HPP_INCLUDED

#include <fcppt/mpl/integral_concept.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
template <typename T1, typename T2>
concept integrals_compatible = fcppt::mpl::integral_concept<T1>
  && fcppt::type_traits::is_integral_constant<T2>::value
  && std::is_same_v<fcppt::type_traits::value_type<T1>,fcppt::type_traits::value_type<T2>>;
}


#endif
