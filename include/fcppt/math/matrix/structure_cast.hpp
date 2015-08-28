//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
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
\brief Converts a matrix into a different matrix of the same dimension using Conv

\ingroup fcpptmathmatrix

\tparam Dest The destination matrix's <code>value_type</code>
*/
template<
	typename Dest,
	typename Conv,
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S
>
inline
Dest
structure_cast(
	fcppt::math::matrix::object<
		T,
		R,
		C,
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
