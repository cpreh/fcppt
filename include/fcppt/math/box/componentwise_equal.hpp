//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_BOX_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/dim/componentwise_equal.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

template<
	typename T,
	math::size_type N
>
bool
componentwise_equal(
	box::basic<
		T,
		N
	> const &_v1,
	box::basic<
		T,
		N
	> const &_v2,
	T const _epsilon
)
{
	return
		math::vector::componentwise_equal(
			_v1.pos(),
			_v2.pos(),
			_epsilon
		)
		&&
		math::dim::componentwise_equal(
			_v1.size(),
			_v2.size(),
			_epsilon
		);
}

}
}
}

#endif
