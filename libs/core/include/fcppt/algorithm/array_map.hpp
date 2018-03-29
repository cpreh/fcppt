//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/container/array_init.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
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

\tparam SourceArray Must be a std::array

\tparam Function Must be a function callable as <code>R (SourceArray::value_type)</code>,
where <code>R</code> is the result type.
**/
template<
	typename SourceArray,
	typename Function
>
inline
auto
array_map(
	SourceArray &&_source,
	Function const &_function
)
->
std::array<
	decltype(
		_function(
			std::declval<
				fcppt::type_traits::value_type<
					fcppt::type_traits::remove_cv_ref_t<
						SourceArray
					>
				>
			>()
		)
	),
	fcppt::container::array_size<
		fcppt::type_traits::remove_cv_ref_t<
			SourceArray
		>
	>::value
>
{
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

	typedef
	std::array<
		decltype(
			_function(
				std::declval<
					fcppt::type_traits::value_type<
						source_array
					>
				>()
			)
		),
		fcppt::container::array_size<
			source_array
		>::value
	>
	result_array;

	return
		fcppt::container::array_init<
			result_array
		>(
			[
				&_source,
				&_function
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					_function(
						fcppt::move_if_rvalue<
							SourceArray
						>(
							std::get<
								_index()
							>(
								_source
							)
						)
					);
			}
		);
}

}
}

#endif
