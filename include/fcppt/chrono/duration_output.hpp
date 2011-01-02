//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_OUTPUT_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_OUTPUT_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <ostream>

namespace fcppt
{
namespace chrono
{

template<
	typename Ch,
	typename Traits,
	typename Rep,
	typename Period
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
	duration<
		Rep,
		Period
	> const &d
)
{
	return
		stream << d.count();
}

}
}

#endif
