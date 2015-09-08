//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_INIT_MOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_INIT_MOVE_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/cast/to_void.hpp>
#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array by moving a function result

\ingroup fcpptalgorithm

Constructs an array of type \a Array by initializing every element with
<code>_function()</code>

\tparam Array Must be a std::array

\tparam Function Must return <code>typename Array::value_type</code>

\param _function The function to call for each element
*/
template<
	typename Array,
	typename Function
>
Array
array_init_move(
	Function const &_function
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			Array
		>::value,
		"Array must be an array"
	);

	return
		fcppt::algorithm::array_fold_static<
			Array
		>(
			[
				&_function
			](
				auto const _index
			)
			{
				fcppt::cast::to_void(
					_index
				);

				return
					_function();
			}
		);
}

}
}

#endif
