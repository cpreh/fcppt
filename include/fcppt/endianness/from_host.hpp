//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_FROM_HOST_HPP_INCLUDED
#define FCPPT_ENDIANNESS_FROM_HOST_HPP_INCLUDED

#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/swap.hpp>

namespace fcppt
{
namespace endianness
{

template<
	typename T
>
T from_host(
	T const &t,
	format::type const fmt)
{
	return fmt == host_format()
		? t
		: swap(t);
}

}
}

#endif
