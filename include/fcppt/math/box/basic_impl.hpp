/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/box/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic()
:
	pos_(),
	dim_()
{}

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::basic<T, N>::basic(
	pos_type const &pos_,
	dim_type const &dim_
)
:
	pos_(pos_),
	dim_(dim_)
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
			pos_type::null(),
			dim_type::null()
		);
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::area() const
{
	return dim_.content();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::w() const
{
	return dim_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::h() const
{
	return dim_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::d() const
{
	return dim_.d();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::pos_type const
fcppt::math::box::basic<T, N>::pos() const
{
	return pos_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::pos_type const
fcppt::math::box::basic<T, N>::max() const
{
	return pos_ + dim_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::dim_type const
fcppt::math::box::basic<T, N>::dim() const
{
	return dim_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::pos(
	size_type const index_
) const
{
	return pos_[index_];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::max(
	size_type const index_
) const
{
	return pos_[index_] + dim_[index_];
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::dim(
	size_type const index_
) const
{
	return dim_[index_];
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
	return pos_.x() + dim_.w();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::bottom() const
{
	return pos_.y() + dim_.h();
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::box::basic<T, N>::value_type
fcppt::math::box::basic<T, N>::back() const
{
	return pos_.z() + dim_.d();
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::w(
	value_type const w_
)
{
	dim_.w() = w_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::h(
	value_type const h_
)
{
	dim_.h() = h_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::d(
	value_type const d_
)
{
	dim_.d() = d_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::pos(
	pos_type const &npos_
)
{
	pos_ = npos_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::dim(
	dim_type const &ndim_
)
{
	dim_ = ndim_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::pos(
	size_type const index_,
	value_type const value_
)
{
	pos_[index_] = value_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::dim(
	size_type const index_,
	value_type const value_
)
{
	dim_[index_] = value_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::left(
	value_type const value_
)
{
	pos_.x() = value_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::top(
	value_type const value_
)
{
	pos_.y() = value_;
}

template<
	typename T,
	fcppt::math::size_type N
>
void
fcppt::math::box::basic<T, N>::front(
	value_type const value_
)
{
	pos_.z() = value_;
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::box::basic<T, N>::operator==(
	basic const &other_
) const
{
	return
		pos_ == other_.pos_
		&& dim_ == other_.dim_;
}

template<
	typename T,
	fcppt::math::size_type N
>
bool
fcppt::math::box::basic<T, N>::operator !=(
	basic const &other_
) const
{
	return !(*this == other_);
}

#endif
