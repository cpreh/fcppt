//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NUMBER_MULTIPLEXER_SET_BITS_HPP_INCLUDED
#define FCPPT_NUMBER_MULTIPLEXER_SET_BITS_HPP_INCLUDED

namespace fcppt
{
namespace number_multiplexer
{
template<typename T>
T
set_bits(
	T const begin,
	T const size,
	T const value,
	T const input)
{
	T const part =
		((1u << begin) - 1u) ^ ((1u << (begin + size)) - 1u);

	return
		(input & ~part) | (value << begin);
}
}
}

#endif
