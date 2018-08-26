//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_OPTIONAL_HPP_INCLUDED

#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/optional/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Transforms a range to another container by applying a function to
every element, only inserting the results that are not empty optionals.

\ingroup fcpptalgorithm

For every element \em e in \a _source, <code>_function(e)</code> is called. If
the result is not an empty optional, it is inserted into the result container.

\tparam Function A function callable as
<code>fcppt::optional::object<TargetContainer::value_type>
(Source::value_type)</code>.
*/
template<
	typename TargetContainer,
	typename Source,
	typename Function
>
TargetContainer
map_optional(
	Source &&_source,
	Function const &_function
)
{
	TargetContainer result;

	for(
		fcppt::algorithm::range_element_type<
			Source
		> element
		:
		_source
	)
	{
		auto result_element(
			_function(
				element
			)
		);

		static_assert(
			fcppt::optional::is_object<
				decltype(
					result_element
				)
			>::value,
			"map_optional requires a function that returns an optional"
		);

		// TODO: maybe_void
		if(
			result_element.has_value()
		)
			result.insert(
				result.end(),
				std::move(
					result_element.get_unsafe()
				)
			);
	}

	return
		result;
}

}
}

#endif
