//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/optimize_map.hpp>
#include <fcppt/algorithm/detail/source_size.hpp>
#include <fcppt/cast/size.hpp>
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
	typename Dest,
	typename Source
>
inline
typename
boost::enable_if<
	fcppt::algorithm::detail::optimize_map<
		Dest,
		Source
	>,
	void
>::type
map_reserve(
	Dest &_dest,
	Source const &_src
)
{
	_dest.reserve(
		// some ranges have signed sizes
		static_cast<
			typename
			Dest::size_type
		>(
			fcppt::algorithm::detail::source_size(
				_src
			)
		)
	);
}

template<
	typename Dest,
	typename Source
>
inline
typename
boost::disable_if<
	fcppt::algorithm::detail::optimize_map<
		Dest,
		Source
	>,
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
