//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_FWD_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_size.hpp>
#include <fcppt/math/matrix/object_fwd.hpp>
#include <fcppt/math/matrix/detail/static_storage_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Typedef helper for static matrices

\ingroup fcpptmathmatrix

\tparam T The matrix's <code>value_type</code>
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C
>
using static_
=
fcppt::math::matrix::object<
	T,
	R,
	C,
	fcppt::math::matrix::detail::static_storage<
		T,
		R,
		C
	>
>;

}
}
}

#endif
