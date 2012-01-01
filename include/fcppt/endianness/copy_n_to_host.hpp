//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_COPY_N_TO_HOST_HPP_INCLUDED
#define FCPPT_ENDIANNESS_COPY_N_TO_HOST_HPP_INCLUDED

#include <fcppt/endianness/copy_n_from_host.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T,
	typename Size
>
T *
copy_n_to_host(
	T const *const beg,
	Size const n,
	T *const dest,
	Size const stride,
	format::type const fmt
)
{
	// these operations are symmetrical
	return copy_n_from_host(
		beg,
		n,
		dest,
		stride,
		fmt
	);
}

}
}

#endif
