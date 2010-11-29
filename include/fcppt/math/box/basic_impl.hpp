//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/box/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <algorithm>

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic()
:
	pos_(),
	dimension_()
{}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic(
	vector const &_pos,
	dim const &_dimension
)
:
	pos_(_pos),
	dimension_(_dimension)
{}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N> const
fcppt::math::box::basic<T, N>::null()
{
	return
		basic<T, N>(
			vector::null(),
			dim::null()
		);
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::area() const
{
	return dimension_.content();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::w() const
{
	return dimension_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::h() const
{
	return dimension_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::d() const
{
	return dimension_.d();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::vector const
fcppt::math::box::basic<T, N>::pos() const
{
	return pos_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::vector const
fcppt::math::box::basic<T, N>::max() const
{
	return pos_ + dimension_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::dim const
fcppt::math::box::basic<T, N>::dimension() const
{
	return dimension_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::pos(
	size_type const _index
) const
{
	return pos_[_index];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::max(
	size_type const _index
) const
{
	return pos_[_index] + dimension_[_index];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::dimension(
	size_type const _index
) const
{
	return dimension_[_index];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::left() const
{
	return pos_.x();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::top() const
{
	return pos_.y();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::front() const
{
	return pos_.z();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::right() const
{
	return pos_.x() + dimension_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::bottom() const
{
	return pos_.y() + dimension_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::back() const
{
	return pos_.z() + dimension_.d();
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::w(
	value_type const _w
)
{
	dimension_.w() = _w;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::h(
	value_type const _h
)
{
	dimension_.h() = _h;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::d(
	value_type const _d
)
{
	dimension_.d() = _d;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::pos(
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
fcppt::math::box::basic<T, N>::dimension(
	dim const &_dimension
)
{
	dimension_ = _dimension;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::pos(
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
fcppt::math::box::basic<T, N>::dimension(
	size_type const _index,
	value_type const _value
)
{
	dimension_[_index] = _value;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::left(
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
fcppt::math::box::basic<T, N>::top(
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
fcppt::math::box::basic<T, N>::front(
	value_type const _value
)
{
	pos_.z() = _value;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::swap(
	basic &_other
)
{
	std::swap(
		pos_,
		_other.pos_
	);

	std::swap(
		dimension_,
		_other.dimension_
	);
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::box::operator==(
	basic<T, N> const &_a,
	basic<T, N> const &_b
)
{
	return
		_a.pos() == _b.pos()
		&& _a.dimension() == _b.dimension();
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::box::operator !=(
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
fcppt::math::box::swap(
	basic<T, N> &_a,
	basic<T, N> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
