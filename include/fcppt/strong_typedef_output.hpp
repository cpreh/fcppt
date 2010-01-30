//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_OUTPUT_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <iosfwd>

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
	> &s,
	strong_typedef<
		T,
		Tag
	> const &t
)
{
	return s << t .operator T const &();
}

}

#endif
