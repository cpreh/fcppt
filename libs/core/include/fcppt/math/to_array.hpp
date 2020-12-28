//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_TO_ARRAY_HPP_INCLUDED
#define FCPPT_MATH_TO_ARRAY_HPP_INCLUDED

#include <fcppt/array/init.hpp>
#include <fcppt/math/to_array_type.hpp>
#include <fcppt/math/detail/linear_access.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Returns the array of an object with static storage

\ingroup fcpptmath
*/
template <typename Type>
inline fcppt::math::to_array_type<Type> to_array(Type const &_value)
{
  return fcppt::array::init<fcppt::math::to_array_type<Type>>(
      [&_value](auto const _index) {
        return fcppt::math::detail::linear_access<_index()>(_value.storage());
      });
}

}
}

#endif
