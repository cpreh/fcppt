//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRETCH_RELATIVE_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_RELATIVE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/box/center.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/structure_cast.hpp>


namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Stretch a box around its center by a given factor
\ingroup fcpptmathbox
\tparam T The box's <code>value_type</code>
\tparam N The box's dimension
\see fcppt::math::box::stretch_absolute
*/
template<typename T,math::size_type N>
box::object<T,N> const
stretch_relative(
	box::object<T,N> const &b,
	typename box::object<T,N>::vector const &factors)
{
	typename object<T,N>::dim const d =
		b.size() *
		fcppt::math::vector::structure_cast<typename object<T,N>::dim>(
			factors);

	return
		object<T,N>(
			center(
				b) -
			fcppt::math::dim::structure_cast<typename object<T,N>::vector>(
				d)/
			fcppt::literal<T>(
				2),
			d);
}
}
}
}

#endif
