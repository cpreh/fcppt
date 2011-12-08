//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_COMPARISON_HPP_INCLUDED

#include <fcppt/math/detail/array_equal.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
bool
operator==(
	basic<T, N, M, S1> const &v1,
	basic<T, N, M, S2> const &v2
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
	typename M,
	typename S1,
	typename S2
>
bool
operator!=(
	basic<T, N, M, S1> const &v1,
	basic<T, N, M, S2> const &v2
)
{
	return
		!(v1 == v2);
}

}
}
}

#endif
