//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DIM_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/detail/array_componentwise_equal.hpp>
#include <fcppt/math/dim/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
componentwise_equal(
	dim::basic<
		T,
		N,
		S1
	> const &_v1,
	dim::basic<
		T,
		N,
		S2
	> const &_v2,
	T const _epsilon
)
{
	return
		math::detail::array_componentwise_equal(
			_v1,
			_v2,
			_epsilon
		);
}

}
}
}

#endif
