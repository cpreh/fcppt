//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Converts a matrix into a different matrix of the same dimension using static_cast
\ingroup fcpptmathmatrix
\tparam Dest The destination matrix's <code>value_type</code>
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row dimension type
\tparam M The matrix's column dimension type
\tparam S The matrix's storage type
\param src The source matrix
*/
template<
	typename Dest,
	typename Conv,
	typename T,
	typename N,
	typename M,
	typename S
>
Dest const
structure_cast(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> const &src
)
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			Dest
		>::value,
		"Dest must be a matrix"
	);

	return
		fcppt::math::detail::structure_cast<
			Dest,
			Conv
		>(
			src
		);
}

}
}
}

#endif
