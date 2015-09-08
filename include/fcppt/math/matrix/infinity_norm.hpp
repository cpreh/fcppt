//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INFINITY_NORM_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag_value.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_c.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates the infinity norm

\ingroup fcpptmathmatrix
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
T
infinity_norm(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_matrix
)
{
	return
		fcppt::algorithm::fold(
			fcppt::math::int_range_count<
				R
			>{},
			std::numeric_limits<
				T
			>::min(),
			[
				&_matrix
			](
				auto const _row,
				T const _maximum_row
			)
			{
				constexpr auto const row(
					fcppt::tag_value(
						_row
					)
				);

				return
					std::max(
						_maximum_row,
						fcppt::algorithm::fold(
							fcppt::math::int_range_count<
								C
							>{},
							fcppt::literal<
								T
							>(
								0
							),
							[
								&_matrix,
								row
							](
								auto const _column,
								T const _current_row_sum
							)
							{
								return
									_current_row_sum
									+
									std::abs(
										fcppt::math::matrix::at_c(
											_matrix,
											fcppt::math::matrix::index<
												row,
												fcppt::tag_value(
													_column
												)
											>{}
										)
									);
							}
						)
					);
			}
		);
}

}
}
}

#endif
