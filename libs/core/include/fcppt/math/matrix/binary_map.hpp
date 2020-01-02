//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_BINARY_MAP_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BINARY_MAP_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_map.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
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
\brief Maps over two matrixs.

\ingroup fcpptmathmatrix
*/
template<
	typename T1,
	typename T2,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S1,
	typename S2,
	typename Function
>
inline
fcppt::math::matrix::static_<
	std::result_of_t<
		Function(
			T1,
			T2
		)
	>,
	R,
	C
>
binary_map(
	fcppt::math::matrix::object<
		T1,
		R,
		C,
		S1
	> const &_left,
	fcppt::math::matrix::object<
		T2,
		R,
		C,
		S2
	> const &_right,
	Function const &_function
)
{
	return
		fcppt::math::detail::binary_map<
			fcppt::math::matrix::static_<
				std::result_of_t<
					Function(
						T1,
						T2
					)
				>,
				R,
				C
			>
		>(
			_left,
			_right,
			_function
		);
}

}
}
}

#endif
