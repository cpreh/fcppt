//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_decl.hpp>


template<
	fcppt::math::size_type Row,
	fcppt::math::size_type Column
>
inline
constexpr
fcppt::math::size_type
fcppt::math::matrix::index<
	Row,
	Column
>::row()
{
	return
		Row;
}

template<
	fcppt::math::size_type Row,
	fcppt::math::size_type Column
>
inline
constexpr
fcppt::math::size_type
fcppt::math::matrix::index<
	Row,
	Column
>::column()
{
	return
		Column;
}

#endif
