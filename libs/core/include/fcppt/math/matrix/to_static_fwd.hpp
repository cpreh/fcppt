//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TO_STATIC_FWD_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TO_STATIC_FWD_HPP_INCLUDED

#include <fcppt/math/matrix/static_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief The static type of a matrix

\ingroup fcpptmathmatrix
*/
template<
	typename Matrix
>
using
to_static
=
fcppt::math::matrix::static_<
	typename
	Matrix::value_type,
	Matrix::static_rows::value,
	Matrix::static_columns::value
>;

}
}
}

#endif
