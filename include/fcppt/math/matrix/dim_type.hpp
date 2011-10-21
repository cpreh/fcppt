//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DIM_TYPE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DIM_TYPE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

typedef math::dim::static_<
	math::size_type,
	2
>::type dim_type;

}
}
}

#endif
