//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	fcppt::math::size_type C
>
inline
fcppt::math::matrix::index
index_absolute(
	fcppt::math::size_type const _absolute
)
{
	return
		fcppt::math::matrix::index{
			fcppt::math::matrix::index::row_t{
				_absolute
				/
				C
			},
			fcppt::math::matrix::index::column_t{
				_absolute
				%
				C
			}
		};
}

}
}
}
}

#endif
