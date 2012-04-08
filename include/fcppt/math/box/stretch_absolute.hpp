//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRETCH_ABSOLUTE_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_ABSOLUTE_HPP_INCLUDED

#include <fcppt/math/box/center.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
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
\brief Stretch a box around its center using an absolute value
\ingroup fcpptmathbox
\tparam T The box's <code>value_type</code>
\tparam N The box's dimension
\see fcppt::math::box::stretch_relative
*/
template<typename T,math::size_type N>
box::object<T,N> const
stretch_absolute(
	box::object<T,N> const &b,
	typename box::object<T,N>::vector const &absolute_values)
{
	return
		box::object<T,N>(
			b.pos() - absolute_values,
			b.size() + static_cast<T>(2) *
			fcppt::math::vector::structure_cast<typename box::object<T,N>::dim>(
				absolute_values));
}
}
}
}

#endif

