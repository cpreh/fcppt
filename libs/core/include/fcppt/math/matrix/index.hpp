//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INDEX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INDEX_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/index_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief A static matrix index

\ingroup fcpptmathmatrix
*/
template<
	fcppt::math::size_type Row,
	fcppt::math::size_type Column
>
struct index
{
	static
	constexpr
	fcppt::math::size_type
	row()
	{
		return
			Row;
	}

	static
	constexpr
	fcppt::math::size_type
	column()
	{
		return
			Column;
	}
};

}
}
}

#endif
