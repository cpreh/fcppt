//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_OUTPUT_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_OUTPUT_HPP_INCLUDED

#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_output.hpp>
#include <ostream>

namespace fcppt
{
namespace chrono
{

template<
	typename Ch,
	typename Traits,
	typename Clock,
	typename Duration
>
std::basic_ostream<
	Ch,
	Traits
> &
operator <<(
	std::basic_ostream<
		Ch,
		Traits
	> &stream,
	time_point<
		Clock,
		Duration
	> const &t
)
{
	return
		stream << t.time_since_epoch();
}

}
}

#endif
