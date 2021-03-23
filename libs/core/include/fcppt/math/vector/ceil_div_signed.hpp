//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_CEIL_DIV_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CEIL_DIV_SIGNED_HPP_INCLUDED

#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/sequence.hpp>
#include <fcppt/math/vector/map.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Division rounded up for signed vectors.

Applies #fcppt::math::ceil_div_signed to each component. Returns
nothing in case _divisor is zero.

\ingroup fcpptmathvector
*/
template <typename T, fcppt::math::size_type N, typename S>
fcppt::optional::object<fcppt::math::vector::static_<T, N>>
ceil_div_signed(fcppt::math::vector::object<T, N, S> const _vector, T const _divisor)
{
  static_assert(std::is_signed<T>::value, "T must be signed");

  return fcppt::math::detail::sequence<fcppt::math::vector::static_<T, N>>(
      fcppt::math::vector::map(_vector, [_divisor](T const _value) {
        return fcppt::math::ceil_div_signed(_value, _divisor);
      }));
}

}
}
}

#endif
