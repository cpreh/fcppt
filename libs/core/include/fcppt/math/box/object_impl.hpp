//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/to_dim.hpp>


template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>::object(
	fcppt::no_init const &_no_init
)
:
	min_(
		_no_init
	),
	max_(
		_no_init
	)
{
}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>::object(
	vector const &_pos,
	dim const &_size
)
:
	min_(
		_pos
	),
	max_(
		_pos
		+
		_size
	)
{
}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>::object(
	vector const &_min,
	vector const &_max
)
:
	min_(
		_min
	),
	max_(
		_max
	)
{
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector &
fcppt::math::box::object<
	T,
	N
>::pos()
{
	return
		min_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector const &
fcppt::math::box::object<
	T,
	N
>::pos() const
{
	return
		min_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector &
fcppt::math::box::object<
	T,
	N
>::max()
{
	return
		max_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::vector const &
fcppt::math::box::object<
	T,
	N
>::max() const
{
	return
		max_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::dim
fcppt::math::box::object<
	T,
	N
>::size() const
{
	return
		fcppt::math::vector::to_dim(
			max_
			-
			min_
		);
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::left() const
{
	return
		min_.x();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::right() const
{
	return
		max_.x();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::top() const
{
	return
		min_.y();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::bottom() const
{
	return
		max_.y();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::front() const
{
	return
		min_.z();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename
fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::back() const
{
	return
		max_.z();
}

#endif
