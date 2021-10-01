//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_FROM_ARRAY_HPP_INCLUDED
#define FCPPT_MATH_FROM_ARRAY_HPP_INCLUDED

#include <fcppt/math/to_array_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math
{
/**
\brief Constructs an object with static storage from an array rvalue

\ingroup fcpptmath
*/
template <typename Type>
inline Type from_array(fcppt::math::to_array_type<Type> &&_value)
{
  return Type{typename Type::storage_type{std::move(_value)}};
}

/**
\brief Constructs an object with static storage from an array lvalue

\ingroup fcpptmath
*/
template <typename Type>
inline Type from_array(fcppt::math::to_array_type<Type> const &_value)
{
  return Type{typename Type::storage_type{_value}};
}

}

#endif
