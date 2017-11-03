//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


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

\tparam TargetContainer Either a container that supports
<code>insert(iterator,value_type)</code> or a <code>std::array</code>.

\tparam SourceRange A range usable with \link fcppt::algorithm::loop\endlink
or in case \a TargetContainer is a <code>std::array</code> then \a SourceRange
must also be a <code>std::array</code> of the same size.

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
	return
		fcppt::algorithm::detail::map<
			TargetContainer
		>(
			std::forward<
				SourceRange
			>(
				_source
			),
			_function
		);
}

}
}

#endif
