//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_INIT_CONST_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_INIT_CONST_HPP_INCLUDED

#include <fcppt/algorithm/array_init.hpp>
#include <fcppt/cast/to_void.hpp>
#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array from a value.

\ingroup fcpptalgorithm

Constructs an array of type \a Array by initializing every element with \a
_value.

\tparam Array Must be a <code>std::array</code>.
*/
template<
	typename Array
>
inline
Array
array_init_const(
	typename Array::value_type const &_value
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			Array
		>::value,
		"Array must be an array"
	);

	return
		fcppt::algorithm::array_init<
			Array
		>(
			[
				&_value
			](
				auto const _index
			)
			{
				fcppt::cast::to_void(
					_index
				);

				return
					_value;
			}
		);
}

}
}

#endif
