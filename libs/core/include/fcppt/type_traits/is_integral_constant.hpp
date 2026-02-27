//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_IS_INTEGRAL_CONSTANT_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::type_traits
{
namespace detail
{
template<typename Type>
struct is_integral_constant
{
 using type = std::false_type;
};

template<typename Type, Type Value>
struct is_integral_constant<std::integral_constant<Type,Value>>
{
 using type = std::true_type;
};
}

/**
\brief Checks if a type is a <code>std::integral_constant</code>.

\ingroup fcppttypetraits
*/
template<typename Type>
using is_integral_constant = fcppt::type_traits::detail::is_integral_constant<Type>::type;

}

#endif
