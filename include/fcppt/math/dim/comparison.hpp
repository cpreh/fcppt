//          Copyright Carl Philipp Reh 2009 - 2015.
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
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator==(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		fcppt::math::detail::array_equal(
			_v1,
			_v2
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator!=(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		!(_v1 == _v2);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator<(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		fcppt::math::detail::array_less(
			_v1,
			_v2
		);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator>(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		_v2 < _v1;
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator<=(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		!(_v2 < _v1);
}

template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
bool
operator>=(
	fcppt::math::dim::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::dim::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		!(_v1 < _v2);
}

}
}
}

#endif
