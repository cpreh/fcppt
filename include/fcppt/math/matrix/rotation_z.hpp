//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROTATION_Z_HPP_INCLUDED

#include <fcppt/math/matrix/static.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T
>
typename static_<T, 4, 4>::type const
rotation_z(
	T angle);

}
}
}

#include <fcppt/math/matrix/detail/rotation_z_impl.hpp>

#endif
