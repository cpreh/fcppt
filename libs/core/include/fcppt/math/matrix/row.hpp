//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED

#include <fcppt/math/matrix/row_type.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Creates a matrix row for initialization

\ingroup fcpptmathmatrix
*/
template<
	typename Type,
	typename ...Args
>
inline
auto
row(
	Type const &_value,
	Args const & ..._args
)
{
	return
		fcppt::math::matrix::row_type<
			Type,
			sizeof...(
				Args
			)
			+
			1u
		>{{
			_value,
			_args...
		}};
}

}
}
}

#endif
