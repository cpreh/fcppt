//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_DIM_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/narrow_cast.hpp>
#include <fcppt/math/dim/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
/**
\brief Shortens a dim to a smaller dimension

\ingroup fcpptmathdim
*/
template <typename Dest, typename T, fcppt::math::size_type N, typename S>
inline Dest narrow_cast(fcppt::math::dim::object<T, N, S> const &_src)
{
  return fcppt::math::detail::narrow_cast<Dest>(_src);
}

}
}
}

#endif
