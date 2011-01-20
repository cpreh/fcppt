//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_RANGE_CHECK_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_RANGE_CHECK_HPP_INCLUDED

#include <fcppt/container/array_decl.hpp>
#include <fcppt/container/out_of_range.hpp>
#include <boost/utility/enable_if.hpp>
#include <cstddef>

namespace fcppt
{
namespace container
{
namespace detail
{

template<
	std::size_t N
>
typename boost::enable_if_c<
	N == 0,
	void
>::type
array_range_check(
	std::size_t
)
{
}

template<
	std::size_t N
>
typename boost::disable_if_c<
	N == 0,
	void
>::type
array_range_check(
	std::size_t const _index
)
{
	if(
		_index >= N
	)
		throw container::out_of_range();
}

}
}
}

#endif
