//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

/// Converts a box into a different box of the same dimension using static_cast
template<
	typename Dest,
	typename T,
	size_type N
>
Dest const
structure_cast(
	basic<T, N> const &src
)
{
	return
		Dest(
			fcppt::math::vector::structure_cast<
				typename Dest::vector
			>(
				src.pos()
			),
			fcppt::math::dim::structure_cast<
				typename Dest::dim
			>(
				src.dimension()
			)
		);
}

}
}
}

#endif
