//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CENTER_HPP_INCLUDED
#define FCPPT_MATH_BOX_CENTER_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>


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
template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector
center(
	fcppt::math::box::object<
		T,
		N
	> const &_box
)
{
	return
		_box.pos()
		+
		fcppt::math::dim::to_vector(
			_box.size()
		)
		/
		fcppt::literal<
			T
		>(
			2
		);
}

}
}
}

#endif
