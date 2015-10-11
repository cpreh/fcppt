//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_JOIN_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_HPP_INCLUDED

#include <fcppt/algorithm/detail/join_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Joins two containers

Joins containers \a _first and all containers from \a _args, by inserting the
containers from \a _args into \a _first.

\ingroup fcpptalgorithm

\param _first The left container

\param _args The other containers, which will be inserted into the left
container

\tparam Container A container class that supports insert of iterator ranges
*/
template<
	typename Container,
	typename... Args
>
inline
typename
std::decay<
	Container
>::type
join(
	Container &&_first,
	Args && ..._args
)
{
	return
		fcppt::algorithm::detail::join_impl(
			std::forward<
				Container
			>(
				_first
			),
			std::forward<
				Args
			>(
				_args
			)...
		);
}

}
}

#endif
