//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_OPTIMIZE_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_OPTIMIZE_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_random_access_iterator.hpp>
#include <fcppt/algorithm/detail/has_reserve.hpp>
#include <fcppt/algorithm/detail/has_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/or.hpp>
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
using optimize_map
=
boost::mpl::and_<
	fcppt::algorithm::detail::has_reserve<
		Dest
	>,
	boost::mpl::or_<
		fcppt::algorithm::detail::has_random_access_iterator<
			Source
		>,
		fcppt::algorithm::detail::has_size<
			Source
		>
	>
>;

}
}
}

#endif
