//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_INTEGRAL_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_INTEGRAL_CONCEPT_HPP_INCLUDED

#include <fcppt/type_traits/is_integral_constant.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{

// TODO(philipp): is_integer is too much.
template <typename Type>
concept integral_concept = fcppt::type_traits::is_integral_constant<Type>::value &&
    std::is_integral_v<fcppt::type_traits::value_type<Type>>;
}

#endif
