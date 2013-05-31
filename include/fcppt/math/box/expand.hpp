//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXPAND_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXPAND_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
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
\brief Expand a box away from its center using an absolute value
\ingroup fcpptmathbox
\tparam T The box's <code>value_type</code>
\tparam N The box's dimension
\see fcppt::math::box::stretch_relative
\see fcppt::math::box::shrink
\see fcppt::math::box::stretch_absolute

In contrast to fcppt::math::box::stretch_absolute, this function (and
its complement fcppt::math::box::shrink) can be used to stretch
boxes with <em>unsigned</em> types in them.

If the box contains a signed type, and the stretch value is negative,
the box will be shrunk instead. In this case, if the size of the box
is smaller than two times the shrink value, behavior is undefined.
*/
template<typename T,fcppt::math::size_type N>
fcppt::math::box::object<T,N> const
expand(
	fcppt::math::box::object<T,N> const &b,
	typename fcppt::math::box::object<T,N>::vector const &absolute_values)
{
	return
		fcppt::math::box::object<T,N>(
			b.pos() - absolute_values,
			b.size() + fcppt::literal<T>(2) *
			fcppt::math::vector::structure_cast<typename box::object<T,N>::dim>(
				absolute_values));
}
}
}
}

#endif
