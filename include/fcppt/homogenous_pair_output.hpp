//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HOMOGENOUS_PAIR_OUTPUT_HPP_INCLUDED
#define FCPPT_HOMOGENOUS_PAIR_OUTPUT_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <ostream>
#include <fcppt/config/external_end.hpp>

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
	homogenous_pair<
		T
	> const &pair_
)
{
	return stream_
		<< stream_.widen('(')
		<< pair_.first
		<< stream_.widen(',')
		<< pair_.second
		<< stream_.widen(')');
}

}

#endif
