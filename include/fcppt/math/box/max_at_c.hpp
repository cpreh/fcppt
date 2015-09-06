//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_MAX_AT_C_HPP_INCLUDED
#define FCPPT_MATH_BOX_MAX_AT_C_HPP_INCLUDED

#include <fcppt/math/at_c.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Return the box's position plus its size at a static index

\ingroup fcpptmathbox

In a 2D graphics coordinate system, where the position would denote the
"top left" of the box, this would denote the "bottom right". Box,
however, doesn't impose any coordinate system.
*/
template<
	fcppt::math::size_type Index,
	typename T,
	fcppt::math::size_type Size
>
T
max_at_c(
	fcppt::math::box::object<
		T,
		Size
	> const &_box
)
{
	return
		fcppt::math::at_c<
			Index
		>(
			_box.pos()
		)
		+
		fcppt::math::at_c<
			Index
		>(
			_box.size()
		);
}

}
}
}

#endif
