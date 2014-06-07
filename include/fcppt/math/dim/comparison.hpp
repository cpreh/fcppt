//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_DIM_COMPARISON_HPP_INCLUDED

#include <fcppt/math/detail/array_equal.hpp>
#include <fcppt/math/detail/array_less.hpp>
#include <fcppt/math/dim/object_impl.hpp>

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
operator==(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		fcppt::math::detail::array_equal(
			v1,
			v2
		);
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator!=(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		!(v1 == v2);
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator<(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		fcppt::math::detail::array_less(
			v1,
			v2
		);
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator>(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		v2 < v1;
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator<=(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		!(v2 < v1);
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator>=(
	object<T, N, S1> const &v1,
	object<T, N, S2> const &v2
)
{
	return
		!(v1 < v2);
}

}
}
}

#endif
