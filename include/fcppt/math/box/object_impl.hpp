//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_decl.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/object_impl.hpp>


template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>::object()
:
	pos_(),
	size_()
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
>::value_type
fcppt::math::box::object<
	T,
	N
>::w() const
{
	return
		size_.w();
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
>::h() const
{
	return size_.h();
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
>::d() const
{
	return
		size_.d();
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
>::dim
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
>::pos(
	size_type const _index
) const
{
	return
		pos_[
			_index
		];
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
typename fcppt::math::box::object<
	T,
	N
>::value_type
fcppt::math::box::object<
	T,
	N
>::size(
	size_type const _index
) const
{
	return
		size_[
			_index
		];
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
>::left() const
{
	return
		pos_.x();
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
>::top() const
{
	return
		pos_.y();
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
>::front() const
{
	return
		pos_.z();
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
>::right() const
{
	return
		pos_.x()
		+
		size_.w();
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
>::bottom() const
{
	return
		pos_.y()
		+
		size_.h();
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
>::back() const
{
	return
		pos_.z()
		+
		size_.d();
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::w(
	value_type const _w
)
{
	size_.w() = _w;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::h(
	value_type const _h
)
{
	size_.h() = _h;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::d(
	value_type const _d
)
{
	size_.d() = _d;
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
	pos_ = _pos;
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
	size_ = _size;
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
	size_type const _index,
	value_type const _value
)
{
	pos_[_index] = _value;
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
	size_type const _index,
	value_type const _value
)
{
	size_[_index] = _value;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::left(
	value_type const _value
)
{
	pos_.x() = _value;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::top(
	value_type const _value
)
{
	pos_.y() = _value;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::object<
	T,
	N
>::front(
	value_type const _value
)
{
	pos_.z() = _value;
}

#endif
