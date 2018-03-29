//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_PUSH_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_PUSH_BACK_HPP_INCLUDED

#include <fcppt/container/array_size.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/container/detail/array_push_back.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Pushes a new element to the back of an array.

\ingroup fcpptcontainer

Pushes \a _new_element to the back of \a _source.

\tparam Source A std::array

\tparam NewElement Must be the same as <code>value_type<Source></code>
*/
template<
	typename Source,
	typename NewElement
>
std::array<
	fcppt::type_traits::value_type<
		fcppt::type_traits::remove_cv_ref_t<
			Source
		>
	>,
	fcppt::container::array_size<
		fcppt::type_traits::remove_cv_ref_t<
			Source
		>
	>::value
	+
	1u
>
array_push_back(
	Source &&_source,
	NewElement && _new_element
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Source
	>
	source_type;

	static_assert(
		fcppt::type_traits::is_std_array<
			source_type
		>::value,
		"Source must be a std::array"
	);

	typedef
	fcppt::type_traits::value_type<
		source_type
	>
	value_type;

	static_assert(
		std::is_same<
			fcppt::type_traits::remove_cv_ref_t<
				NewElement
			>,
			value_type
		>::value,
		"Source must be the same type as the array element type"
	);

	typedef
	fcppt::container::array_size<
		source_type
	>
	source_size;

	typedef
	std::array<
		value_type,
		source_size::value
		+
		1u
	>
	dest_array;

	return
		fcppt::container::detail::array_push_back<
			dest_array
		>(
			std::make_index_sequence<
				source_size::value
			>{},
			std::forward<
				Source
			>(
				_source
			),
			std::forward<
				NewElement
			>(
				_new_element
			)
		);
}

}
}

#endif
