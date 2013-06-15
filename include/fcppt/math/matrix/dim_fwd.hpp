//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DIM_FWD_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DIM_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief The two-dimensional dim type

\ingroup fcpptmathmatrix
*/
typedef fcppt::math::dim::static_<
	fcppt::math::size_type,
	2
> dim;

}
}
}

#endif
