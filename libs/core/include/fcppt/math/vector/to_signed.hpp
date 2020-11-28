//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_TO_SIGNED_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_TO_SIGNED_HPP_INCLUDED

#include <fcppt/cast/to_signed_fun.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
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
\brief Converts a vector into a corresponding signed vector

\ingroup fcpptmathvector
*/
template <typename T, fcppt::math::size_type N, typename S>
inline fcppt::math::vector::static_<std::make_signed_t<T>, N>
to_signed(fcppt::math::vector::object<T, N, S> const &_src)
{
  return fcppt::math::vector::structure_cast<
      fcppt::math::vector::static_<std::make_signed_t<T>, N>,
      fcppt::cast::to_signed_fun>(_src);
}

}
}
}

#endif
