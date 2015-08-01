//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_MAP_HPP_INCLUDED
#define FCPPT_MATH_DIM_MAP_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/dim/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Maps over the elements of a dim

\ingroup fcpptmathdim
*/
template<
	typename T,
	typename N,
	typename S,
	typename Function
>
inline
fcppt::math::dim::object<
	typename
	std::result_of<
		Function(
			T
		)
	>::type,
	N,
	fcppt::math::static_storage<
		typename
		std::result_of<
			Function(
				T
			)
		>::type,
		N
	>
>
map(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_value,
	Function const &_function
)
{
	return
		fcppt::math::map<
			fcppt::math::dim::object<
				typename
				std::result_of<
					Function(
						T
					)
				>::type,
				N,
				fcppt::math::static_storage<
					typename
					std::result_of<
						Function(
							T
						)
					>::type,
					N
				>
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
