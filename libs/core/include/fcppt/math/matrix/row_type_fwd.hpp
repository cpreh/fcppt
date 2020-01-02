//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROW_TYPE_FWD_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_TYPE_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/static_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief The type of matrix row

\ingroup fcpptmathmatrix
*/
template<
	typename T,
	fcppt::math::size_type C
>
using
row_type
=
fcppt::math::vector::static_<
	T,
	C
>;

}
}
}

#endif
