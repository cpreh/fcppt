//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_FOLD_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_FOLD_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Constructs an array from a function

\ingroup fcpptalgorithm

Constructs an array of type \a Array by calling <code>_function(Index)</code>
for every index.

\tparam Array Must be a std::array

\tparam Function Must be a function callable with
<code>_function(Index)</code>, returning elements of type <code>typename
Array::value_type</code>

\param _function The function to use for initialization
*/
template<
	typename Array,
	typename Function
>
inline
Array
array_fold(
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
				return
					_function(
						_index()
					);
			}
		);
}

}
}

#endif
