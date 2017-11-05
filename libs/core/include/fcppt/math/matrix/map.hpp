//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_MAP_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_MAP_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/map.hpp>
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
\brief Maps over the elements of a matrix.

\ingroup fcpptmathmatrix
*/
template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S,
	typename Function
>
inline
fcppt::math::matrix::static_<
	typename
	std::result_of<
		Function(
			T
		)
	>::type,
	R,
	C
>
map(
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_value,
	Function const &_function
)
{
	return
		fcppt::math::detail::map<
			fcppt::math::matrix::static_<
				typename
				std::result_of<
					Function(
						T
					)
				>::type,
				R,
				C
			>
		>(
			_value,
			_function
		);
}

}
}
}

#endif
