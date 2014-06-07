//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_STATIC_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_STATIC_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	std::size_t Index,
	typename T,
	std::size_t N,
	typename F,
	typename... Args
>
typename std::enable_if<
	Index == N,
	std::array<
		T,
		N
	>
>::type
array_fold_static(
	F const &,
	Args && ..._args
)
{
	return
		std::array<
			T,
			N
		>{{
			std::forward<
				Args
			>(
				_args
			)...
		}};
}

template<
	std::size_t Index,
	typename T,
	std::size_t N,
	typename F,
	typename... Args
>
typename std::enable_if<
	Index != N,
	std::array<
		T,
		N
	>
>::type
array_fold_static(
	F const &_function,
	Args && ..._args
)
{
	return
		fcppt::algorithm::detail::array_fold_static<
			Index + 1,
			T,
			N
		>(
			_function,
			std::forward<
				Args
			>(
				_args
			)...,
			_function. template operator()<
				Index
			>()
		);
}

}
}
}

#endif
