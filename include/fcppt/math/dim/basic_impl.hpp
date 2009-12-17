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


#ifndef FCPPT_MATH_DIM_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/math/dim/max_ctor_params.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <numeric>
#include <functional>
#include <iterator>
#include <algorithm>

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S>::basic()
{}

template<
	typename T,
	typename N,
	typename S
>
template<
	typename In
>
fcppt::math::dim::basic<T, N, S>::basic(
	In const beg,
		typename boost::enable_if<
		type_traits::is_iterator<
			In
		>,
		In
	>::type const end)
{
	math::detail::initial_size(
		storage,
		std::distance(
			beg,
			end));
	std::copy(
		beg,
		end,
		data());
}

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE FCPPT_MATH_DIM_MAX_CTOR_PARAMS
#define FCPPT_MATH_DETAIL_TEMPLATE_PRE\
	template<\
		typename T,\
		typename N,\
		typename S\
	>
#define FCPPT_MATH_DETAIL_DEF_PRE\
	fcppt::math::dim::basic<T, N, S>

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	basic)

#undef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE

#define FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(fcppt::math::dim::basic, op)

FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(+=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(-=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(*=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(/=)
FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR(%=)

#undef FCPPT_MATH_DETAIL_DEF_PRE
#undef FCPPT_MATH_DETAIL_TEMPLATE_PRE
#undef FCPPT_MATH_DIM_BASIC_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator*=(
	value_type const &v)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] *= v;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S> &
fcppt::math::dim::basic<T, N, S>::operator/=(
	value_type const &v)
{
	for(size_type i = 0; i < size(); ++i)
		(*this)[i] /= v;
	return *this;
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::operator[](
	size_type const index)
{
	return storage[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::operator[](
	size_type const index) const
{
	return storage[index];
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::pointer
fcppt::math::dim::basic<T, N, S>::data()
{
	return math::detail::storage_data(
		storage);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_pointer
fcppt::math::dim::basic<T, N, S>::data() const
{
	return math::detail::storage_data(
		storage);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::size_type
fcppt::math::dim::basic<T, N, S>::size() const
{
	return static_cast<
		size_type
	>(
		math::detail::storage_dim(
			storage));
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::w()
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::w() const
{
	return math::detail::checked_access<0>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::h()
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::h() const
{
	return math::detail::checked_access<1>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::reference
fcppt::math::dim::basic<T, N, S>::d()
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::const_reference
fcppt::math::dim::basic<T, N, S>::d() const
{
	return math::detail::checked_access<2>(*this);
}

template<
	typename T,
	typename N,
	typename S
>
typename fcppt::math::dim::basic<T, N, S>::size_type
fcppt::math::dim::basic<T, N, S>::content() const
{
	return std::accumulate(
		this->begin(),
		this->end(),
		1,
		std::multiplies<size_type>());
}

template<
	typename T,
	typename N,
	typename S
>
fcppt::math::dim::basic<T, N, S> const
fcppt::math::dim::basic<T, N, S>::null()
{
	basic ret;
	for(size_type i = 0; i < N::value; ++i)
		ret[i] = static_cast<value_type>(0);
	return ret;
}

#endif
