//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_MAP_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
/**
 * \brief Transforms a container using a functor to another container
 * \tparam TargetContainer Must be default-constructible
 * \ingroup fcpptalgorithm
 * \details
 * This is equivalent to:
 *
 * <pre>
 * std::transform(source.begin(),source.end(),inserter,f)
 * </pre>
 *
 * with an appropriate <code>inserter</code>.
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
