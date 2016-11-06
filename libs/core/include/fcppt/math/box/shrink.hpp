//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_SHRINK_HPP_INCLUDED
#define FCPPT_MATH_BOX_SHRINK_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Shrink a box towards its center using an absolute value

\ingroup fcpptmathbox
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>
shrink(
	fcppt::math::box::object<
		T,
		N
	> const &_box,
	typename
	fcppt::math::box::object<
		T,
		N
	>::vector const &_absolute_values
)
{
	return
		fcppt::math::box::object<
			T,
			N
		>(
			_box.pos()
			+
			_absolute_values
			,
			_box.max()
			-
			_absolute_values
		);
}

}
}
}

#endif
