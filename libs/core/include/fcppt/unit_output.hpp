//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIT_OUTPUT_HPP_INCLUDED
#define FCPPT_UNIT_OUTPUT_HPP_INCLUDED

#include <fcppt/unit_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Outputs a unit to a basic_ostream.

\ingroup fcpptvarious
*/
template<
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::unit const &
)
{
	return
		_stream
		<<
		_stream.widen('(')
		<<
		_stream.widen(')');
}

}

#endif
