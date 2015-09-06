//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_MAX_AT_HPP_INCLUDED
#define FCPPT_MATH_BOX_MAX_AT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Return the box's position plus its size at an index

\ingroup fcpptmathbox

\see fcppt::math::box::max_at_c
*/
template<
	typename T,
	fcppt::math::size_type Size
>
T
max_at(
	fcppt::math::box::object<
		T,
		Size
	> const &_box,
	fcppt::math::size_type const _index
)
{
	return
		_box.pos()[
			_index
		]
		+
		_box.size()[
			_index
		];
}

}
}
}

#endif
