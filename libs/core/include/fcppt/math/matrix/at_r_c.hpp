//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_AT_R_C_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_AT_R_C_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_r.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Access an element using compile-time constants for both row and column

\ingroup fcpptmathmatrix

\tparam Matrix Must be an \link fcppt::math::matrix::object\endlink.

\tparam R The index of the row
\tparam C The index of the column
*/
template<
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename Matrix
>
inline
fcppt::container::to_reference_type<
	fcppt::container::to_reference_type<
		std::remove_reference_t<
			Matrix
		>
	>
>
at_r_c(
	Matrix &_value
)
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			std::remove_cv_t<
				Matrix
			>
		>::value,
		"Matrix must be a matrix"
	);

	fcppt::container::to_reference_type<
		Matrix
	> const view{
		fcppt::math::matrix::at_r<
			R
		>(
			_value
		)
	};

	return
		fcppt::math::vector::at<
			C
		>(
			view
		);
}

}
}
}

#endif
