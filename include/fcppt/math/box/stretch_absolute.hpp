//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_STRETCH_ABSOLUTE_HPP_INCLUDED
#define FCPPT_MATH_BOX_STRETCH_ABSOLUTE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/box/center.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


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
\see fcppt::math::box::expand
\see fcppt::math::box::shrink

This function is only defined for signed types. For unsigned types,
see fcppt::math::box::expand and fcppt::math::box::shrink instead.

The function will expand the box if <code>absolute_values</code> is
positive and shrink the box if <code>absolute_values</code> is
negative.
*/
template<typename T,fcppt::math::size_type N>
fcppt::math::box::object<T,N> const
stretch_absolute(
	fcppt::math::box::object<T,N> const &b,
	typename fcppt::math::box::object<T,N>::vector const &absolute_values)
{
	static_assert(
		std::is_signed<T>::value,
		"stretch_absolute can only be used on signed boxes"
	);

	return
		fcppt::math::box::object<T,N>(
			b.pos() - absolute_values,
			b.size() + fcppt::literal<T>(2) *
			fcppt::math::vector::structure_cast<typename fcppt::math::box::object<T,N>::dim>(
				absolute_values));
}
}
}
}

#endif

