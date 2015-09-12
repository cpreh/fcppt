//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_HPP_INCLUDED

#include <fcppt/algorithm/detail/loop.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Iterates through a normal range or an MPL range.

\ingroup fcpptalgorithm

Iterates through \a _range, calling \a _body for every element of the range.
If \a Range is an MPL range, it is the same as \link
fcppt::mpl::for_each\endlink.

\tparam Range A forward range or an MPL range.

\tparam Body A function callable as <code>void (Range::value_type)</code>
*/
template<
	typename Range,
	typename Body
>
inline
void
loop(
	Range &&_range,
	Body const &_body
)
{
	fcppt::algorithm::detail::loop(
		std::forward<
			Range
		>(
			_range
		),
		_body
	);
}

}
}

#endif
