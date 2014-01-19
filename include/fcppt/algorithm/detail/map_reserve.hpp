//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/test_reserve.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Result,
	typename SizeType
>
inline
typename
boost::enable_if<
	fcppt::algorithm::detail::test_reserve<
		Result
	>,
	void
>::type
map_reserve(
	Result &_result,
	SizeType const _size
)
{
	_result.reserve(
		_size
	);
}

template<
	typename Result,
	typename SizeType
>
inline
typename
boost::disable_if<
	fcppt::algorithm::detail::test_reserve<
		Result
	>,
	void
>::type
map_reserve(
	Result &,
	SizeType
)
{
}

}
}
}

#endif
