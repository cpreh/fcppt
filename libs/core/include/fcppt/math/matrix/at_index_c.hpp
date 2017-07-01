//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_AT_INDEX_C_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_AT_INDEX_C_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_c.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/vector/at_c.hpp>
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
\brief Access an element using a compile-time constant for both coordinates

\ingroup fcpptmathmatrix

\tparam Matrix Must be an \link fcppt::math::matrix::object\endlink.
*/
template<
	typename Matrix,
	fcppt::math::size_type R,
	fcppt::math::size_type C
>
inline
fcppt::container::to_reference_type<
	fcppt::container::to_reference_type<
		typename
		std::remove_reference<
			Matrix
		>::type
	>
>
at_index_c(
	Matrix &_value,
	fcppt::math::matrix::index<
		R,
		C
	>
)
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			typename
			std::decay<
				Matrix
			>::type
		>::value,
		"Matrix must be a matrix"
	);

	auto const view(
		fcppt::math::matrix::at_c<
			R
		>(
			_value
		)
	);

	return
		fcppt::math::vector::at_c<
			C
		>(
			view
		);
}

}
}
}

#endif
