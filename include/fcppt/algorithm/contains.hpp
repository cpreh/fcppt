//          Copyright Carl Philipp Reh 2009 - 2014.
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
\brief Checks if a given \p value is inside the range [\p beg,\p end]
\ingroup fcpptalgorithm
\tparam In A forward iterator
\tparam T A type compatible with the iterator's value type

This is equivalent to
\code
std::find(beg, end, value) != end
\endcode
*/
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

/**
\brief Checks if a given \p value is inside a range
\ingroup fcpptalgorithm

\tparam Container A container type having <code>begin</code> and <code>end</code> member functions

\tparam T The container's value type

This is equivalent to
\code
contains(container.begin(), container.end(), value)
\endcode
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
		fcppt::algorithm::contains(
			container.begin(),
			container.end(),
			value
		);
}

}
}

#endif
