//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DETERMINANT_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{
template <typename T, typename S>
T determinant(fcppt::math::matrix::object<T, 1, 1, S> const &_matrix)
{
  return fcppt::math::matrix::at_r_c<0, 0>(_matrix);
}

template <typename T, fcppt::math::size_type N, typename S>
std::enable_if_t<
    !fcppt::math::matrix::has_dim<fcppt::math::matrix::object<T, N, N, S>, 1, 1>::value,
    T>
determinant(fcppt::math::matrix::object<T, N, N, S> const &_matrix)
{
  return fcppt::algorithm::fold(
      fcppt::math::int_range_count<N>{},
      fcppt::literal<T>(0),
      [&_matrix](auto const _row, T const _sum) {
        FCPPT_USE(_row);

        using row = fcppt::tag_type<decltype(_row)>;

        T const coeff{
            row::value % fcppt::literal<fcppt::math::size_type>(2) ==
                    fcppt::literal<fcppt::math::size_type>(0)
                ? fcppt::literal<T>(1)
                : fcppt::literal<T>(-1)};

        constexpr fcppt::math::size_type const column{0u};

        return _sum +
               coeff * fcppt::math::matrix::at_r_c<row::value, column>(_matrix) *
                   fcppt::math::matrix::detail::determinant(
                       fcppt::math::matrix::delete_row_and_column<row::value, column>(_matrix));
      });
}

}
}
}
}

#endif
