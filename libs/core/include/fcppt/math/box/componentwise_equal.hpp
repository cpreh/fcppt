//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_BOX_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Compare two boxes component-wise using an epsilon

\ingroup fcpptmathbox

Componentwise in this context means: Compare the positions and the sizes
component-wise. For each component of the position and the size, check if the
components differ by more than the specified epsilon. If so, return
<code>false</code>.
*/
template<
	typename T,
	fcppt::math::size_type N
>
inline
bool
componentwise_equal(
	fcppt::math::box::object<
		T,
		N
	> const &_v1,
	fcppt::math::box::object<
		T,
		N
	> const &_v2,
	T const _epsilon
)
{
	return
		fcppt::math::vector::componentwise_equal(
			_v1.pos(),
			_v2.pos(),
			_epsilon
		)
		&&
		fcppt::math::vector::componentwise_equal(
			_v1.max(),
			_v2.max(),
			_epsilon
		);
}

}
}
}

#endif
