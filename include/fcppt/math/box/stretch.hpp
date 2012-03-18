//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRETCH_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_HPP_INCLUDED

#include <fcppt/math/box/center.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>


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
*/
template<typename T,size_type N>
object<T,N> const
stretch(
	object<T,N> const &b,
	T const factor)
{
	typename object<T,N>::dim const d =
		b.size() * factor;
	return
		object<T,N>(
			center(
				b) -
			fcppt::math::dim::structure_cast<typename object<T,N>::vector>(
				d)/
			static_cast<T>(
				2),
			d);
}
}
}
}

#endif
