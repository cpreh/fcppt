//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_NULL_HPP_INCLUDED
#define FCPPT_MATH_BOX_NULL_HPP_INCLUDED

#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/dim/null.hpp>
#include <fcppt/math/vector/null.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Returns the null box

\ingroup fcpptmathbox
*/
template<
	typename Box
>
inline
Box
null()
{
	static_assert(
		fcppt::math::box::is_box<
			Box
		>::value,
		"Box must be a box"
	);

	return
		Box(
			fcppt::math::vector::null<
				typename
				Box::vector
			>(),
			fcppt::math::dim::null<
				typename
				Box::dim
			>()
		);
}

}
}
}

#endif
