//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_size_reserve.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	fcppt::algorithm::detail::has_size_reserve<
		Dest,
		Source
	>::value,
	void
>::type
map_reserve(
	Dest &_dest,
	Source const &_src
)
{
	_dest.reserve(
		static_cast<
			typename
			Dest::size_type
		>(
			_src.size()
		)
	);
}

template<
	typename Dest,
	typename Source
>
typename
std::enable_if<
	!fcppt::algorithm::detail::has_size_reserve<
		Dest,
		Source
	>::value,
	void
>::type
map_reserve(
	Dest &,
	Source const &
)
{
}

}
}
}

#endif
