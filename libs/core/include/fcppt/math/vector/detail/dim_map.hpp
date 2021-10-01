//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_DETAIL_DIM_MAP_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DETAIL_DIM_MAP_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_map.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::vector::detail
{
template <
    typename L,
    typename R,
    fcppt::math::size_type N,
    typename S1,
    typename S2,
    typename Function>
inline fcppt::math::vector::static_<std::invoke_result_t<Function, L, R>, N> dim_map(
    fcppt::math::vector::object<L, N, S1> const &_left,
    fcppt::math::dim::object<R, N, S2> const &_right,
    Function const &_function)
{
  return fcppt::math::detail::binary_map<
      fcppt::math::vector::static_<std::invoke_result_t<Function, L, R>, N>>(_left, _right, _function);
}

}

#endif
