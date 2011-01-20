//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_FROM_BIG_ENDIAN_HPP_INCLUDED
#define FCPPT_ENDIANNESS_FROM_BIG_ENDIAN_HPP_INCLUDED

#include <fcppt/endianness/is_big_endian.hpp>
#include <fcppt/endianness/swap.hpp>

namespace fcppt
{
namespace endianness
{
template<typename T>
T from_big_endian(T const &t)
{
	if(!is_big_endian())
		return swap(t);
	return t;
}
}
}

#endif
