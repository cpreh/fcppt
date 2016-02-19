//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Iterates through a range

\ingroup fcpptalgorithm

Iterates through \a _range, calling \a _body for every element of the range.
The implementation for a specific range type is handled by \link
fcppt::algorithm::loop_break_impl\endlink.

\tparam Body A function callable as <code>void (T)</code> for every type
<code>T</code> in \a Range
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
	fcppt::algorithm::loop_break(
		std::forward<
			Range
		>(
			_range
		),
		[
			&_body
		](
			auto &&_loop_element
		)
		{
			_body(
				std::forward<
					decltype(
						_loop_element
					)
				>(
					_loop_element
				)
			);

			return
				fcppt::loop::continue_;
		}
	);
}

}
}

#endif
