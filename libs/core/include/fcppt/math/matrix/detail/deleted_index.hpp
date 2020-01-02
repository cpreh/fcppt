//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_DELETED_INDEX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DELETED_INDEX_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/math/size_type.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

constexpr
inline
fcppt::math::size_type
deleted_index(
	fcppt::math::size_type const _cur,
	fcppt::math::size_type const _rem
)
{
	return
		_cur
		>=
		_rem
		?
			_cur
			+
			fcppt::literal<
				fcppt::math::size_type
			>(
				1
			)
		:
			_cur
		;
}

}
}
}
}

#endif
