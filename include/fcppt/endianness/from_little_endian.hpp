//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_FROM_LITTLE_ENDIAN_HPP_INCLUDED
#define FCPPT_ENDIANNESS_FROM_LITTLE_ENDIAN_HPP_INCLUDED

#include <fcppt/endianness/is_little_endian.hpp>
#include <fcppt/endianness/swap.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T
>
T from_little_endian(
	T const &t)
{
	if(!is_little_endian())
		return swap(t);
	return t;
}

}
}

#endif
