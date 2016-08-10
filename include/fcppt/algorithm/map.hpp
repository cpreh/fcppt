//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/algorithm/detail/map_reserve.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Transforms a range to another container by applying a function to every
element.

\ingroup fcpptalgorithm

For every element \em e in \a _source, <code>_function(e)</code> is inserted
into the result container.

\note As an optimization the result container has its capacity set to the
source range's size at the start, if possible. For this to work, the result
container needs a <code>reserve</code> function, and the source range needs a
<code>size</code> function or must be a random access range.

\tparam Function A function callable as <code>TargetContainer::value_type
(SourceRange::value_type)</code>.
*/
template<
	typename TargetContainer,
	typename SourceRange,
	typename Function
>
TargetContainer
map(
	SourceRange &&_source,
	Function const &_function
)
{
	TargetContainer result;

	fcppt::algorithm::detail::map_reserve(
		result,
		_source
	);

	for(
		fcppt::algorithm::range_element_type<
			SourceRange
		> element
		:
		_source
	)
		result.insert(
			result.end(),
			_function(
				element
			)
		);

	return
		result;
}

}
}

#endif
