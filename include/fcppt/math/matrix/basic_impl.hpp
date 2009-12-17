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


#ifndef FCPPT_MATH_MATRIX_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/detail/resize.hpp>
#include <fcppt/math/matrix/basic_decl.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/detail/array_adapter_impl.hpp>
#include <fcppt/math/detail/storage_data.hpp>
#include <fcppt/math/detail/storage_dim.hpp>
#include <fcppt/math/detail/view_storage_impl.hpp>
#include <fcppt/math/detail/make_variadic_constructor.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/make_op_def.hpp>
#include <fcppt/assert.hpp>
#include <algorithm>

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic()
{}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	dim_type const &dim)
{
	resize(dim);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename In
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	In const beg,
	In const end)
{
	math::detail::initial_size(
		storage,
		std::distance(
			beg,
			end
		)
	);

	std::copy(
		beg,
		end,
		data()
	);
}
template<
	typename T,
	typename N,
	typename M,
	typename S
>
template<
	typename Container
>
fcppt::math::matrix::basic<T, N, M, S>::basic(
	dim_type const &d,
	Container const &c)
{
	resize(d);

	FCPPT_ASSERT(c.size() == size());

	std::copy(
		c.begin(),
		c.end(),
		storage.begin());
}

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS
#define FCPPT_MATH_DETAIL_TEMPLATE_PRE\
	template<\
		typename T,\
		typename N,\
		typename M,\
		typename S\
	>
#define FCPPT_MATH_DETAIL_DEF_PRE\
	fcppt::math::matrix::basic<T, N, M, S>

FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(
	basic)

#undef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE

#define FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DEF(fcppt::math::matrix::basic, op)

FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(+=)
FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR(-=)

#undef FCPPT_MATH_DETAIL_DEF_PRE
#undef FCPPT_MATH_DETAIL_TEMPLATE_PRE
#undef FCPPT_MATH_MATRIX_BASIC_DEFINE_OPERATOR

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::reference
fcppt::math::matrix::basic<T, N, M, S>::operator[](
	size_type const j)
{
	return reference(
		typename reference::storage_type(
			data(),
			j,
			columns(),
			rows()));
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::const_reference const
fcppt::math::matrix::basic<T, N, M, S>::operator[](
	size_type const j) const
{
	return const_reference(
		typename const_reference::storage_type(
			data(),
			j,
			columns(),
			rows()));
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::pointer
fcppt::math::matrix::basic<T, N, M, S>::data()
{
	return math::detail::storage_data(
		storage);
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::const_pointer
fcppt::math::matrix::basic<T, N, M, S>::data() const
{
	return const_cast<
		basic &
	>(
		*this).data();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::size() const
{
	return static_cast<
		size_type
	>(
		math::detail::storage_dim(
			storage
		)
	);
}
template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::rows() const
{
	return dim_base::rows();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::size_type
fcppt::math::matrix::basic<T, N, M, S>::columns() const
{
	return dim_base::columns();
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
typename fcppt::math::matrix::basic<T, N, M, S>::dim_type const
fcppt::math::matrix::basic<T, N, M, S>::dim() const
{
	return dim_type(
		columns(),
		rows());
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::basic<T, N, M, S> const
fcppt::math::matrix::basic<T, N, M, S>::identity()
{
	basic<T, N, M, S> ret;
	for(size_type i = 0; i < N::value; ++i)
		for(size_type j = 0; j < M::value; ++j)
			ret[i][j] =
				i == j
				? static_cast<T>(1)
				: static_cast<T>(0);
	return ret;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
void
fcppt::math::matrix::basic<T, N, M, S>::resize(
	dim_type const &d)
{
	detail::resize(
		d,
		static_cast<
			dim_base &
		>(*this),
		storage
	);
}

#endif
