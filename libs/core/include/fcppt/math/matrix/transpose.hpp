//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_c.hpp>
#include <fcppt/math/matrix/index.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates a transposed matrix

\ingroup fcpptmathmatrix
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
fcppt::math::matrix::static_<
	T,
	C,
	R
>
transpose(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_matrix
)
{
	return
		fcppt::math::matrix::init<
			fcppt::math::matrix::static_<
				T,
				C,
				R
			>
		>(
			[
				&_matrix
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::math::matrix::at_c(
						_matrix,
						fcppt::math::matrix::index<
							_index.column,
							_index.row
						>()
					);
			}
		);
}

}
}
}

#endif
