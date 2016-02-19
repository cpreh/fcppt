//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_JOIN_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_JOIN_IMPL_HPP_INCLUDED

#include <fcppt/algorithm/detail/join_all.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Container,
	typename... Args
>
inline
Container
join_impl(
	Container const &_first,
	Args && ..._args
)
{
	return
		fcppt::algorithm::detail::join_all(
			Container(
				_first
			),
			std::forward<
				Args
			>(
				_args
			)...
		);
}

template<
	typename Container,
	typename... Args
>
inline
typename
boost::disable_if<
	std::is_lvalue_reference<
		Container
	>,
	Container
>::type
join_impl(
	Container &&_first,
	Args && ..._args
)
{
	return
		fcppt::algorithm::detail::join_all(
			std::move(
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
}

#endif
