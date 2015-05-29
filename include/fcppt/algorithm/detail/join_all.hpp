//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_JOIN_ALL_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_JOIN_ALL_HPP_INCLUDED

#include <fcppt/move_iterator_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
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
	typename Result,
	typename... Args
>
inline
Result
join_all(
	Result &&_first
)
{
	return
		std::move(
			_first
		);
}

template<
	typename Result,
	typename Container,
	typename... Args
>
inline
typename
std::remove_cv<
	Result
>::type
join_all(
	Result &&_result,
	Container &&_container,
	Args &&... _args
)
{
	_result.insert(
		_result.end(),
		fcppt::move_iterator_if_rvalue<
			Container
		>(
			_container.begin()
		),
		fcppt::move_iterator_if_rvalue<
			Container
		>(
			_container.end()
		)
	);

	return
		fcppt::algorithm::detail::join_all(
			std::move(
				_result
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
