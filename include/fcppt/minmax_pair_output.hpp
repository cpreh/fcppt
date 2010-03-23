//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MINMAX_PAIR_OUTPUT_HPP_INCLUDED
#define FCPPT_MINMAX_PAIR_OUTPUT_HPP_INCLUDED

#include <fcppt/minmax_pair_impl.hpp>
#include <ostream>
#include <iosfwd>

namespace fcppt
{

template<
	typename T,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator << (
	std::basic_ostream<
		Ch,
		Traits
	> &stream_,
	minmax_pair<
		T
	> const &pair_
)
{
	return stream_
		<< stream_.widen('(')
		<< pair_.min()
		<< stream_.widen(',')
		<< pair_.max()
		<< stream_.widen(')');
}

}

#endif
