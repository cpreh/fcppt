//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ARRAY_BINARY_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_ARRAY_BINARY_MAP_HPP_INCLUDED

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
\brief Applies a function to each pair of elements of two arrays and returns an
array containing the results.

\ingroup fcpptalgorithm

Calls <code>_function(element1, element2)</code> for every element1 of \a
_source1 and element2 of \a _source2.

\tparam SourceArray1 Must be a std::array

\tparam SourceArray2 Must be a std::array

\tparam Function Must be a function callable as <code>R (SourceArray1::value_type, SourceArray2::value_type)</code>,
where <code>R</code> is the result type.
**/
template<
	typename SourceArray1,
	typename SourceArray2,
	typename Function
>
auto
array_binary_map(
	SourceArray1 &&_source1,
	SourceArray2 &&_source2,
	Function const &_function
)
->
std::array<
	fcppt::type_traits::remove_cv_ref_t<
		decltype(
			_function(
				std::declval<
					fcppt::type_traits::value_type<
						fcppt::type_traits::remove_cv_ref_t<
							SourceArray1
						>
					>
				>(),
				std::declval<
					fcppt::type_traits::value_type<
						fcppt::type_traits::remove_cv_ref_t<
							SourceArray2
						>
					>
				>()
			)
		)
	>,
	fcppt::container::array_size<
		fcppt::type_traits::remove_cv_ref_t<
			SourceArray1
		>
	>::value
>
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		SourceArray1
	>
	source1;

	typedef
	fcppt::type_traits::remove_cv_ref_t<
		SourceArray2
	>
	source2;

	static_assert(
		fcppt::type_traits::is_std_array<
			source1
		>::value,
		"Source1 must be a std::array"
	);

	static_assert(
		fcppt::type_traits::is_std_array<
			source2
		>::value,
		"Source2 must be a std::array"
	);

	static_assert(
		fcppt::container::array_size<
			source1
		>::value
		==
		fcppt::container::array_size<
			source2
		>::value,
		"Both arrays must have the same number of elements"
	);

	typedef
	std::array<
		fcppt::type_traits::remove_cv_ref_t<
			decltype(
				_function(
					std::declval<
						fcppt::type_traits::value_type<
							source1
						>
					>(),
					std::declval<
						fcppt::type_traits::value_type<
							source2
						>
					>()
				)
			)
		>,
		fcppt::container::array_size<
			source1
		>::value
	>
	result_type;

	return
		fcppt::container::array_init<
			result_type
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
						fcppt::move_if_rvalue<
							SourceArray1
						>(
							std::get<
								index::value
							>(
								_source1
							)
						),
						fcppt::move_if_rvalue<
							SourceArray2
						>(
							std::get<
								index::value
							>(
								_source2
							)
						)
					);
			}
		);
}

}
}

#endif
