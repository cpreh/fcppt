//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Output operator for strong typedefs

\ingroup fcpptstrongtypedef
*/
template<
	typename Ch,
	typename Traits,
	typename T,
	typename Tag
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
	fcppt::strong_typedef<
		T,
		Tag
	> const &_value
)
{
	return
		_stream
		<<
		_value.get();
}

}

#endif
