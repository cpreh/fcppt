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
