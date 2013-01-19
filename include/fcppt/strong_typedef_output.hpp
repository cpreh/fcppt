//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

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
	strong_typedef<
		T,
		Tag
	> const &_value
)
{
	return
		_stream << _value.get();
}

}

#endif
