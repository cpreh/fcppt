//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Creates a matrix row for initialization

\ingroup fcpptmathmatrix
*/
template <
    typename Type,
    typename... Args,
    typename = std::enable_if_t<std::conjunction_v<std::is_same<
        fcppt::type_traits::remove_cv_ref_t<Args>,
        fcppt::type_traits::remove_cv_ref_t<Type>>...>>>
inline fcppt::math::matrix::row_type<
    fcppt::type_traits::remove_cv_ref_t<Type>,
    fcppt::cast::size<fcppt::math::size_type>(sizeof...(Args) + 1U)>
row(Type &&_value, Args &&..._args)
{
  return fcppt::math::matrix::row_type<
      fcppt::type_traits::remove_cv_ref_t<Type>,
      fcppt::cast::size<fcppt::math::size_type>(sizeof...(Args) + 1U)>{
      std::forward<Type>(_value), std::forward<Args>(_args)...};
}
}
}
}

#endif
