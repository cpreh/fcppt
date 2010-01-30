//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_CIRCLE_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/circle/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

template<
	typename T
>
fcppt::math::circle::basic<T>::basic(
	point_type const &origin_,
	const_reference radius_)
:
	origin_(origin_),
	radius_(radius_)
{}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::point_type &
fcppt::math::circle::basic<T>::origin()
{
	return origin_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::point_type const &
fcppt::math::circle::basic<T>::origin() const
{
	return origin_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::reference
fcppt::math::circle::basic<T>::radius()
{
	return radius_;
}

template<
	typename T
>
typename fcppt::math::circle::basic<T>::const_reference
fcppt::math::circle::basic<T>::radius() const
{
	return radius_;
}

#endif
