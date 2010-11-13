#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <algorithm>
#include <iterator>

namespace fcppt
{
namespace algorithm
{
/**
	Takes a source container (or a source "range", if you will),
	applies a functor to each element and inserts it at the end of the
	newly created target container
 */
template
<
	typename TargetContainer,
	typename SourceContainer,
	typename Functor
>
TargetContainer const
map(
	SourceContainer const &s,
	Functor const &f)
{
	TargetContainer t;
	::std::transform(
		s.begin(),
		s.end(),
		::std::inserter<TargetContainer>(
			t,
			t.end()),
		f);
	return t;
}
}
}

#endif
