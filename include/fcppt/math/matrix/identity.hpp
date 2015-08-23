//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_IDENTITY_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_IDENTITY_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/static.hpp>


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
fcppt::math::matrix::static_<
	typename
	Matrix::value_type,
	Matrix::n_wrapper::value,
	Matrix::m_wrapper::value
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
	typename
	Matrix::value_type
	value_type;

	typedef
	fcppt::math::matrix::static_<
		value_type,
		Matrix::n_wrapper::value,
		Matrix::m_wrapper::value
	>
	result_type;

	typedef
	typename
	result_type::size_type
	size_type;

	result_type ret{
		fcppt::no_init()
	};

	// TODO: Create an init function
	for(
		size_type i = 0; i < ret.rows(); ++i
	)
		for(
			size_type j = 0; j < ret.columns(); ++j
		)
			ret[i][j] =
				i == j
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

	return
		ret;
}

}
}
}

#endif
