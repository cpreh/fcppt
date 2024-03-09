//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::matrix
{
/**
\brief Creates a matrix row for initialization

\ingroup fcpptmathmatrix
*/
template <typename Type, typename... Args>
inline fcppt::math::matrix::row_type<
    std::remove_cvref_t<Type>,
    fcppt::cast::size<fcppt::math::size_type>(sizeof...(Args) + 1U)>
row(Type &&_value, Args &&..._args)
  requires(
      std::conjunction_v<std::is_same<std::remove_cvref_t<Args>, std::remove_cvref_t<Type>>...>)
{
  return fcppt::math::matrix::row_type<
      std::remove_cvref_t<Type>,
      fcppt::cast::size<fcppt::math::size_type>(sizeof...(Args) + 1U)>{
      std::forward<Type>(_value), std::forward<Args>(_args)...};
}
}

#endif
