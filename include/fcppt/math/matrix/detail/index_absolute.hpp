//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_INDEX_ABSOLUTE_HPP_INCLUDED

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
	typename SizeType,
	SizeType C
>
inline
fcppt::math::matrix::index<
	SizeType
>
index_absolute(
	SizeType const _absolute
)
{
	typedef
	fcppt::math::matrix::index<
		SizeType
	>
	index_type;

	return
		index_type{
			typename
			index_type::row_t{
				_absolute
				/
				C
			}
			,
			typename
			index_type::column_t{
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
