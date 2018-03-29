//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_BINARY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_BINARY_MAP_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/container/array_init.hpp>
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
\brief Applies a function to each pair of elements of two arrays and returns an
array containing the results.

\ingroup fcpptalgorithm

Calls <code>_function(element1, element2)</code> for every element1 of \a
_source1 and element2 of \a _source2.

\tparam TargetArray Must be a <code>std::array</code>.

\tparam SourceCount The number of elements in the source arrays.

\tparam Function Must be a function callable as <code>TargetArray::value_type (SourceType1, SourceType2)</code>.
**/
template<
	typename TargetArray,
	typename SourceType1,
	typename SourceType2,
	std::size_t SourceCount,
	typename Function
>
TargetArray
array_binary_map(
	std::array<
		SourceType1,
		SourceCount
	> const &_source1,
	std::array<
		SourceType2,
		SourceCount
	> const &_source2,
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
		"Both arrays must have the same number of elements"
	);

	return
		fcppt::container::array_init<
			TargetArray
		>(
			[
				&_source1,
				&_source2,
				&_function
			]
			(
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				typedef
				decltype(
					_index
				)
				index;

				return
					_function(
						std::get<
							index::value
						>(
							_source1
						),
						std::get<
							index::value
						>(
							_source2
						)
					);
			}
		);
}

}
}

#endif
