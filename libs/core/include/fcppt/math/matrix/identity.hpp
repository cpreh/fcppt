//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IDENTITY_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IDENTITY_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/use.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/to_static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Returns the identity matrix;

\ingroup fcpptmathmatrix
*/
template<
	typename Matrix
>
fcppt::math::matrix::to_static<
	Matrix
>
identity()
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			Matrix
		>::value,
		"Matrix must be a matrix"
	);

	typedef
	fcppt::math::matrix::to_static<
		Matrix
	>
	result_type;

	typedef
	typename
	result_type::value_type
	value_type;

	return
		fcppt::math::matrix::init<
			result_type
		>(
			[](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					_index.row
					==
					_index.column
					?
						fcppt::literal<
							value_type
						>(
							1
						)
					:
						fcppt::literal<
							value_type
						>(
							0
						)
					;
			}
		);
}

}
}
}

#endif
