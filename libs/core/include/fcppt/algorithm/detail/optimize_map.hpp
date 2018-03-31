//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_OPTIMIZE_MAP_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_OPTIMIZE_MAP_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_random_access_iterator.hpp>
#include <fcppt/algorithm/detail/has_reserve.hpp>
#include <fcppt/container/detail/has_size.hpp>
#include <fcppt/type_traits/is_brigand_sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/logical/and.hpp>
#include <brigand/functions/logical/or.hpp>
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
using
optimize_map
=
::brigand::and_<
	fcppt::algorithm::detail::has_reserve<
		Dest
	>,
	::brigand::or_<
		fcppt::algorithm::detail::has_random_access_iterator<
			Source
		>,
		fcppt::container::detail::has_size<
			Source
		>,
		fcppt::type_traits::is_brigand_sequence<
			Source
		>
	>
>;

}
}
}

#endif
