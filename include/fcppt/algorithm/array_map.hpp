//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/algorithm/array_fold_static.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Applies a function to every element of an array and returns an array of
the results.

\ingroup fcpptalgorithm

Calls <code>_function(element)</code> for every element of \a _source.

Example:

\snippet algorithm.cpp array_map

\tparam TargetArray Must be a std::array

\tparam SourceType Can be any type

\tparam SourceCount The number of elements in the source array

\tparam Function Must be a function callable as <code>TargetArray::value_type
(SourceType)</code>.
**/
template<
	typename TargetArray,
	typename SourceType,
	std::size_t SourceCount,
	typename Function
>
inline
TargetArray
array_map(
	std::array<
		SourceType,
		SourceCount
	> const &_source,
	Function const &_function
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			TargetArray
		>::value,
		"TargetArray must be a std::array"
	);

	static_assert(
		fcppt::container::array_size<
			TargetArray
		>::value
		==
		SourceCount,
		"All arrays must have the same number of elements"
	);

	return
		fcppt::algorithm::array_fold_static<
			TargetArray
		>(
			[
				&_source,
				&_function
			](
				auto const _index
			)
			{
				return
					_function(
						_source[
							_index()
						]
					);
			}
		);
}

}
}

#endif
