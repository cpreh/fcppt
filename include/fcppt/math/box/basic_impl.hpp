//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/box/basic_decl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/dim.hpp>


template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic()
:
	pos_(),
	size_()
{
}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic(
	vector const &_pos,
	dim const &_size
)
:
	pos_(_pos),
	size_(_size)
{
}

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
fcppt::math::box::basic<T, N>::content() const
{
	return size_.content();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::w() const
{
	return size_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::h() const
{
	return size_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::d() const
{
	return size_.d();
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
	return pos_ + size_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::dim const
fcppt::math::box::basic<T, N>::size() const
{
	return size_;
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
	return pos_[_index] + size_[_index];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::size(
	size_type const _index
) const
{
	return size_[_index];
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
	return pos_.x() + size_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::bottom() const
{
	return pos_.y() + size_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::back() const
{
	return pos_.z() + size_.d();
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
	size_.w() = _w;
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
	size_.h() = _h;
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
	size_.d() = _d;
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
fcppt::math::box::basic<T, N>::size(
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
fcppt::math::box::basic<T, N>::size(
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
	pos_.swap(
		_other.pos_
	);

	size_.swap(
		_other.size_
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
		&& _a.size() == _b.size();
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
