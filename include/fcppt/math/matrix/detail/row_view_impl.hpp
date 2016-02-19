//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/detail/row_view_decl.hpp>


template<
	typename T,
	fcppt::math::size_type C
>
fcppt::math::matrix::detail::row_view<
	T,
	C
>::row_view(
	pointer const _data,
	size_type const _index,
	size_type const _columns
)
:
	rep_(
		_data
		+
		_index
		*
		_columns
	)
{
}

template<
	typename T,
	fcppt::math::size_type C
>
typename
fcppt::math::matrix::detail::row_view<
	T,
	C
>::iterator
fcppt::math::matrix::detail::row_view<
	T,
	C
>::begin() const
{
	return
		rep_;
}

template<
	typename T,
	fcppt::math::size_type C
>
typename
fcppt::math::matrix::detail::row_view<
	T,
	C
>::iterator
fcppt::math::matrix::detail::row_view<
	T,
	C
>::end() const
{
	return
		rep_
		+
		C;
}

#endif
