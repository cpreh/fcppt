//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_COPY_N_SWAPPED_HPP_INCLUDED
#define FCPPT_ENDIANNESS_COPY_N_SWAPPED_HPP_INCLUDED

#include <fcppt/endianness/copy_swapped.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T,
	typename Size
>
T *
copy_n_swapped(
	T const *const beg,
	Size const n,
	T *const dest,
	Size const stride)
{
	return copy_swapped(
		beg,
		beg + n,
		dest,
		stride
	);
}

}
}

#endif
