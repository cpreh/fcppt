//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_BINARY_MAP_HPP_INCLUDED
#define FCPPT_MATH_DIM_BINARY_MAP_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_map.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
/**
\brief Maps over two dims.

\ingroup fcpptmathdim
*/
template <
    typename T1,
    typename T2,
    fcppt::math::size_type N,
    typename S1,
    typename S2,
    typename Function>
inline fcppt::math::dim::static_<std::invoke_result_t<Function, T1, T2>, N> binary_map(
    fcppt::math::dim::object<T1, N, S1> const &_left,
    fcppt::math::dim::object<T2, N, S2> const &_right,
    Function const &_function)
{
  return fcppt::math::detail::binary_map<
      fcppt::math::dim::static_<std::invoke_result_t<Function, T1, T2>, N>>(_left, _right, _function);
}

}
}
}

#endif
