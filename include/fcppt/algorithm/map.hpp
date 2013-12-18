//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Transforms a container using a functor to another container

\ingroup fcpptalgorithm

For every element \em e in \a _source, _function(e) is inserted into the result
container.
*/
template
<
	typename TargetContainer,
	typename SourceContainer,
	typename Functor
>
TargetContainer
map(
	SourceContainer const &_source,
	Functor const &_function
)
{
	TargetContainer result;

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
