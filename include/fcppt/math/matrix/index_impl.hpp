//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_decl.hpp>


inline
fcppt::math::matrix::index::index(
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

inline
fcppt::math::size_type
fcppt::math::matrix::index::row() const
{
	return
		row_.get();
}

inline
fcppt::math::size_type
fcppt::math::matrix::index::column() const
{
	return
		column_.get();
}

#endif
