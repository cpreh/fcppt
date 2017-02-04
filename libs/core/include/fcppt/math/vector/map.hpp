//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MAP_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MAP_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/map.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Maps over the elements of a vector

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S,
	typename Function
>
inline
fcppt::math::vector::static_<
	typename
	std::result_of<
		Function(
			T
		)
	>::type,
	N
>
map(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_value,
	Function const &_function
)
{
	return
		fcppt::math::detail::map<
			fcppt::math::vector::static_<
				typename
				std::result_of<
					Function(
						T
					)
				>::type,
				N
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
