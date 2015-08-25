//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/index_decl.hpp>


template<
	typename SizeType
>
fcppt::math::matrix::index<
	SizeType
>::index(
	row_t const _row,
	column_t const _column
)
:
	row_{
		_row
	},
	column_{
		_column
	}
{
}

template<
	typename SizeType
>
typename
fcppt::math::matrix::index<
	SizeType
>::size_type
fcppt::math::matrix::index<
	SizeType
>::row() const
{
	return
		row_.get();
}

template<
	typename SizeType
>
typename
fcppt::math::matrix::index<
	SizeType
>::size_type
fcppt::math::matrix::index<
	SizeType
>::column() const
{
	return
		column_.get();
}

#endif
