//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C
>
using static_storage
=
fcppt::math::static_storage<
	T,
	R * C
>;

}
}
}

#endif
