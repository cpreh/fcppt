//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CENTER_HPP_INCLUDED
#define FCPPT_MATH_BOX_CENTER_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace box
{
/**
\brief Returns the center of the box
\ingroup fcpptmathbox
\tparam N The box's dimension
\tparam T The box's <code>value_type</code>

Note that this might not calculate the box's "real" center, since the
calculation is performed using <code>T</code>, which might be integral.
*/
template<typename T,size_type N>
typename basic<T,N>::vector const
center(
	basic<T,N> const &b)
{
	return
		b.pos() +
		fcppt::math::dim::structure_cast<typename basic<T,N>::vector>(
			b.size())/
		static_cast<T>(2);
}
}
}
}

#endif
