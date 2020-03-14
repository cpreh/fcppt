//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/container/array/size.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Applies a function to every element of an array and returns an array of
the results.

\ingroup fcpptcontainerarray

Calls <code>_function(element)</code> for every element of \a _source.

Example:

\snippet container/array.cpp array_map

\tparam Array Must be a <code>std::array</code>.

\tparam Function Must be a function callable as <code>R (Array::value_type)</code>,
where <code>R</code> is the result type.
**/
template<
	typename Array,
	typename Function
>
inline
auto
map(
	Array &&_source,
	Function const &_function
)
->
std::array<
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Array
			>(
				std::declval<
					fcppt::container::to_reference_type<
						std::remove_reference_t<
							Array
						>
					>
				>()
			)
		)
	),
	fcppt::container::array::size<
		fcppt::type_traits::remove_cv_ref_t<
			Array
		>
	>::value
>
{
	using
	source_array
	=
	fcppt::type_traits::remove_cv_ref_t<
		Array
	>;

	static_assert(
		fcppt::type_traits::is_std_array<
			source_array
		>::value,
		"Array must be a std::array"
	);

	using
	result_array
	=
	std::array<
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Array
				>(
					std::declval<
						fcppt::container::to_reference_type<
							std::remove_reference_t<
								Array
							>
						>
					>()
				)
			)
		),
		fcppt::container::array::size<
			source_array
		>::value
	>;

	return
		fcppt::container::array::init<
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
							Array
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
}

#endif
