//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/generate_binary_vectors.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Returns the 2^N corner points (vertices) of the given box.
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>
*/
template<
	typename T,
	fcppt::math::size_type N
>
std::array
<
	fcppt::math::vector::static_<T,N>,
	fcppt::literal<
		std::size_t
	>(
		1u
	) << N
> const
corner_points(
	box::object<T,N> const &_box
)
{
	typedef
	fcppt::math::vector::static_<T,N>
	vector_type;

	typedef
	std::array
	<
		fcppt::math::vector::static_<T,N>,
		fcppt::literal<
			std::size_t
		>(
			1u
		)
		<< N
	>
	result_type;

	result_type result(
		fcppt::math::generate_binary_vectors<T,N>()
	);

	for(
		auto &item : result
	)
		item =
			_box.pos()
			+
			item
			*
			fcppt::math::dim::structure_cast<
				vector_type
			>(
				_box.size()
			);

	return result;
}

}
}
}

#endif
