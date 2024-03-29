//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::math::matrix
{
/**
\brief Multiplies a matrix by a vector

\ingroup fcpptmathmatrix
*/
template <
    typename Left,
    typename Right,
    fcppt::math::size_type R,
    fcppt::math::size_type C,
    typename S1,
    typename S2>
fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right), R> operator*(
    fcppt::math::matrix::object<Left, R, C, S1> const &_left,
    fcppt::math::vector::object<Right, C, S2> const &_right)
{
  using result_type =
      fcppt::math::vector::static_<FCPPT_MATH_DETAIL_BINARY_TYPE(Left, *, Right), R>;

  return fcppt::math::vector::init<result_type>(
      [&_left, &_right]<fcppt::math::size_type Row>(fcppt::math::size_constant<Row>)
      {
        using value_type = fcppt::type_traits::value_type<result_type>;

        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
        return fcppt::algorithm::fold(
            fcppt::math::int_range_count<C>{},
            fcppt::literal<value_type>(0),
            [&_left, &_right]<fcppt::math::size_type Col>(
                fcppt::tag<fcppt::math::size_constant<Col>>, value_type const _sum)
            {
              return _sum + fcppt::math::matrix::at_r_c<Row, Col>(_left) *
                                fcppt::math::vector::at<Col>(_right);
            });
        FCPPT_PP_POP_WARNING
      });
}

}

#endif
