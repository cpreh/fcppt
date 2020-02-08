//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CHECK_SEQUENCE_HPP_INCLUDED

#include <fcppt/container/tuple/types_of.hpp>
#include <fcppt/optional/is_object.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{
namespace detail
{

template<
	typename Result,
	typename Source
>
struct check_sequence
{
	typedef
	fcppt::type_traits::value_type<
		Source
	>
	source_optional;

	static_assert(
		fcppt::optional::is_object<
			source_optional
		>::value,
		"The source must be a container of optionals"
	);

	static_assert(
		std::is_same<
			fcppt::type_traits::value_type<
				Result
			>,
			fcppt::type_traits::value_type<
				source_optional
			>
		>::value,
		"ResultContainer must be a container of the source's success type"
	);
};

template<
	typename Result,
	typename... Types
>
struct check_sequence<
	Result,
	std::tuple<
		Types...
	>
>
{
	static_assert(
		std::conjunction_v<
			fcppt::optional::is_object<
				Types
			>...
		>,
		"Source must be a std::tuple of optionals"
	);

	static_assert(
		fcppt::type_traits::is_std_tuple<
			Result
		>::value,
		"Result must be a std::tuple"
	);

	static_assert(
		std::is_same_v<
			::metal::list<
				fcppt::type_traits::value_type<
					Types
				>...
			>,
			fcppt::container::tuple::types_of<
				Result
			>
		>,
		"The tuple types must match"
	);
};

}
}
}

#endif
