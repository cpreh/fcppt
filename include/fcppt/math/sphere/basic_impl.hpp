//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/compare.hpp>
#include <fcppt/math/sphere/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::sphere::basic<T, N>::basic(
	point_type const &_origin,
	const_reference _radius
)
:
	origin_(_origin),
	radius_(_radius)
{}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::point_type &
fcppt::math::sphere::basic<T, N>::origin()
{
	return origin_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::point_type const &
fcppt::math::sphere::basic<T, N>::origin() const
{
	return origin_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::reference
fcppt::math::sphere::basic<T, N>::radius()
{
	return radius_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::const_reference
fcppt::math::sphere::basic<T, N>::radius() const
{
	return radius_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::sphere::basic<T, N>::swap(
	basic &_other
)
{
	std::swap(
		origin_,
		_other.origin_
	);

	std::swap(
		radius_,
		_other.radius_
	);
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::sphere::operator==(
	basic<T, N> const &_a,
	basic<T, N> const &_b
)
{
	return
		_a.origin() == _b.origin()
		&& math::compare(
			_a.radius(),
			_b.radius()
		);
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::sphere::operator!=(
	basic<T, N> const &_a,
	basic<T, N> const &_b
)
{
	return !(_a == _b);
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::sphere::swap(
	basic<T, N> &_a,
	basic<T, N> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
