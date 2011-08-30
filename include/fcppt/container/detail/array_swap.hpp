//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_SWAP_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_SWAP_HPP_INCLUDED

#include <fcppt/container/array_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <algorithm>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename T,
	std::size_t N
>
typename boost::enable_if_c<
	N == 0,
	void
>::type
array_swap(
	container::array<T, N> &,
	container::array<T, N> &
)
{
}

template<
	typename T,
	std::size_t N
>
typename boost::disable_if_c<
	N == 0,
	void
>::type
array_swap(
	container::array<T, N> &_array1,
	container::array<T, N> &_array2
)
{
	using std::swap;

	for(
		std::size_t i = 0;
		i < N;
		++i
	)
		swap(
			_array1[i],
			_array2[i]
		);
}

}
}
}

#endif
