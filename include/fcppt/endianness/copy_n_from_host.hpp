//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_COPY_N_FROM_HOST_HPP_INCLUDED
#define FCPPT_ENDIANNESS_COPY_N_FROM_HOST_HPP_INCLUDED

#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/endianness/copy_n_swapped.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/endianness/host_format.hpp>


namespace fcppt
{
namespace endianness
{

template<
	typename T,
	typename Size
>
T *
copy_n_from_host(
	T const *const beg,
	Size const n,
	T *const dest,
	Size const stride,
	format::type const fmt
)
{
	return fmt == host_format()
		? algorithm::copy_n(
			beg,
			n,
			dest)
		: copy_n_swapped(
			beg,
			n,
			dest,
			stride
		);
}

}
}

#endif
