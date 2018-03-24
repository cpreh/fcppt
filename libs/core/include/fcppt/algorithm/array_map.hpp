//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/array_init.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>


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

\tparam SourceArray Must be a std::array

\tparam Function Must be a function callable as <code>TargetArray::value_type
(SourceArray::value_type)</code>.
**/
template<
	typename TargetArray,
	typename SourceArray,
	typename Function
>
inline
TargetArray
array_map(
	SourceArray &&_source,
	Function const &_function
)
{
	static_assert(
		fcppt::type_traits::is_std_array<
			TargetArray
		>::value,
		"TargetArray must be a std::array"
	);

	typedef
	fcppt::type_traits::remove_cv_ref_t<
		SourceArray
	>
	source_array;

	static_assert(
		fcppt::type_traits::is_std_array<
			source_array
		>::value,
		"SourceArray must be a std::array"
	);

	static_assert(
		fcppt::container::array_size<
			TargetArray
		>::value
		==
		fcppt::container::array_size<
			source_array
		>::value,
		"All arrays must have the same number of elements"
	);

	return
		fcppt::algorithm::array_init<
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
						fcppt::move_if_rvalue<
							SourceArray
						>(
							_source[
								_index()
							]
						)
					);
			}
		);
}

}
}

#endif
