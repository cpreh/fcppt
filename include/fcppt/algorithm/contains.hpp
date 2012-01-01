//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Checks if a given \p value is inside the range [\p beg,\p end]
 * \ingroup fcpptalgorithm
 * \details
 * This is equivalent to
 *
 * <pre>
 * std::find(beg, end, value) != end
 * </pre>.
 **/
template<
	typename In,
	typename T
>
bool
contains(
	In const beg,
	In const end,
	T const &value
)
{
	return
		::std::find(
			beg,
			end,
			value
		)
		!= end;
}

/// Checks if a given @a value is in the container @a container
/**
 * Equivalent to contains(container.begin(), container.end(), value)
*/
template<
	typename Container,
	typename T
>
bool
contains(
	Container const &container,
	T const &value
)
{
	return
		algorithm::contains(
			container.begin(),
			container.end(),
			value
		);
}

}
}

#endif
