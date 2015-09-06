//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_decl.hpp>
#include <fcppt/math/vector/dim.hpp>


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
	pos_(
		_no_init
	),
	size_(
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
	pos_(
		_pos
	),
	size_(
		_size
	)
{
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::vector &
fcppt::math::box::object<
	T,
	N
>::pos()
{
	return
		pos_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::vector const &
fcppt::math::box::object<
	T,
	N
>::pos() const
{
	return
		pos_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::vector
fcppt::math::box::object<
	T,
	N
>::max() const
{
	return
		pos_
		+
		size_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::dim &
fcppt::math::box::object<
	T,
	N
>::size()
{
	return
		size_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::dim const &
fcppt::math::box::object<
	T,
	N
>::size() const
{
	return
		size_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::max(
	size_type const _index
) const
{
	return
		pos_[
			_index
		]
		+
		size_[
			_index
		];
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::pos(
	vector const &_pos
)
{
	pos_ =
		_pos;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::size(
	dim const &_size
)
{
	size_ =
		_size;
}

#endif
