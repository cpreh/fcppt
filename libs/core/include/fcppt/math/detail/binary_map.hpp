//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_BINARY_MAP_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_BINARY_MAP_HPP_INCLUDED

#include <fcppt/algorithm/array_binary_map.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/to_array.hpp>
#include <fcppt/math/to_array_type.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Source1,
	typename Source2,
	typename Function
>
inline
Dest
binary_map(
	Source1 const &_source1,
	Source2 const &_source2,
	Function const &_function
)
{
	return
		fcppt::math::from_array<
			Dest
		>(
			fcppt::algorithm::array_binary_map<
				fcppt::math::to_array_type<
					Dest
				>
			>(
				fcppt::math::to_array(
					_source1
				),
				fcppt::math::to_array(
					_source2
				),
				_function
			)
		);
}

}
}
}

#endif
