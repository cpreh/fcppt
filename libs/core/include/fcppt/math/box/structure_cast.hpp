//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/structure_cast.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Converts a box into a different box of the same dimension using Conv
\ingroup fcpptmathbox
\tparam T The original box's <code>value_type</code>
\tparam Dest The destination box's <code>value_type</code>
\tparam N The box's dimension
*/
template<
	typename Dest,
	typename Conv,
	typename T,
	fcppt::math::size_type N
>
Dest
structure_cast(
	fcppt::math::box::object<
		T,
		N
	> const &_src
)
{
	static_assert(
		fcppt::math::box::is_box<
			Dest
		>::value,
		"Dest must be a box"
	);

	return
		Dest(
			fcppt::math::vector::structure_cast<
				typename Dest::vector,
				Conv
			>(
				_src.pos()
			),
			fcppt::math::dim::structure_cast<
				typename Dest::dim,
				Conv
			>(
				_src.size()
			)
		);
}

}
}
}

#endif
