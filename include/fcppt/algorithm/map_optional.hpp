//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED

#include <fcppt/is_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\ingroup fcpptalgorithm
*/
template
<
	typename TargetContainer,
	typename SourceContainer,
	typename Functor
>
TargetContainer
map_optional(
	SourceContainer const &_source,
	Functor const &_function
)
{
	typedef
	typename
	std::result_of<
		Functor(
			typename SourceContainer::value_type const &
		)
	>::type
	result_type;

	static_assert(
		fcppt::is_optional<
			typename
			std::decay<
				result_type
			>::type
		>::value,
		"map_optional requires a function that returns an optional"
	);

	TargetContainer result;

	for(
		auto const &element
		:
		_source
	)
	{
		auto result_element(
			_function(
				element
			)
		);

		if(
			result_element
		)
			result.insert(
				result.end(),
				std::move(
					*result_element
				)
			);
	}

	return
		result;
}

}
}

#endif
