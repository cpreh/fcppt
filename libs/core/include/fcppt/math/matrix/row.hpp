//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ROW_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/row_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


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
	static_assert(
		std::conjunction_v<
			std::is_same<
				Args,
				Type
			>...
		>,
		"All row elements must have the same type"
	);

	return
		fcppt::math::matrix::row_type<
			Type,
			fcppt::cast::size<
				fcppt::math::size_type
			>(
				sizeof...(
					Args
				)
				+
				1u
			)
		>{
			_value,
			_args...
		};
}

}
}
}

#endif
