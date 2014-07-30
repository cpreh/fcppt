//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/map_reserve.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Transforms a container to another container by applying a function to
evert element.

\ingroup fcpptalgorithm

For every element \em e in \a _source, _function(e) is inserted into the result
container. As an optimization the result container has its capacity set to the
source container's size at the start.

\param _function A function accepting elements from \a _source and returning
objects of the \a TargetContainer's element type.

\param _source The container to be mapped.
*/
template<
	typename TargetContainer,
	typename SourceContainer,
	typename Function
>
TargetContainer
map(
	SourceContainer const &_source,
	Function const &_function
)
{
	TargetContainer result;

	fcppt::algorithm::detail::map_reserve(
		result,
		_source
	);

	for(
		auto const &element
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
