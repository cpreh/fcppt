//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/detail/row_view_decl.hpp>


template<
	typename T,
	typename N
>
fcppt::math::matrix::detail::row_view<T, N>::row_view(
	pointer const _data,
	size_type const _index,
	size_type const _stride,
	size_type const _size
)
:
	rep_(
		_data + _index * _stride
	),
	size_(
		_size
	)
{
}

template<
	typename T,
	typename N
>
typename fcppt::math::matrix::detail::row_view<
	T,
	N
>::iterator
fcppt::math::matrix::detail::row_view<
	T,
	N
>::begin() const
{
	return
		rep_;
}

template<
	typename T,
	typename N
>
typename fcppt::math::matrix::detail::row_view<
	T,
	N
>::pointer
fcppt::math::matrix::detail::row_view<
	T,
	N
>::data() const
{
	return
		rep_;
}

template<
	typename T,
	typename N
>
typename fcppt::math::matrix::detail::row_view<
	T,
	N
>::size_type
fcppt::math::matrix::detail::row_view<
	T,
	N
>::size() const
{
	return
		size_;
}

#endif
