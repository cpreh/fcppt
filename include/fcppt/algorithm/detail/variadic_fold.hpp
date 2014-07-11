//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_VARIADIC_FOLD_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_VARIADIC_FOLD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Operation,
	typename Result,
	typename... Args
>
inline
Result
variadic_fold(
	Operation const &,
	Result &&_first
)
{
	return
		std::move(
			_first
		);
}

template<
	typename Operation,
	typename Result1,
	typename Result2,
	typename... Args
>
inline
typename
std::remove_cv<
	Result1
>::type
variadic_fold(
	Operation const &_operation,
	Result1 &&_first,
	Result2 &&_second,
	Args &&... _args
)
{
	return
		fcppt::algorithm::detail::variadic_fold(
			_operation,
			_operation(
				std::move(
					_first
				),
				std::move(
					_second
				)
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
