//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_UNTUPLE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_UNTUPLE_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	bool Move,
	std::size_t Cur,
	std::size_t Size,
	typename Enable = void
>
struct untuple;

template<
	bool Move,
	std::size_t Cur,
	std::size_t Size
>
struct untuple<
	Move,
	Cur,
	Size,
	typename
	std::enable_if<
		Cur
		==
		Size
	>::type
>
{
	template<
		typename Tuple,
		typename Function,
		typename... Args
	>
	inline
	static
	decltype(
		auto
	)
	execute(
		Tuple &,
		Function const &_function,
		Args &&... _fcppt_untuple_args
	)
	{
		return
			_function(
				fcppt::move_if<
					Move
				>(
					_fcppt_untuple_args
				)...
			);
	}
};

template<
	bool Move,
	std::size_t Cur,
	std::size_t Size
>
struct untuple<
	Move,
	Cur,
	Size,
	typename
	std::enable_if<
		Cur
		!=
		Size
	>::type
>
{
	template<
		typename Tuple,
		typename Function,
		typename... Args
	>
	inline
	static
	decltype(
		auto
	)
	execute(
		Tuple &_tuple,
		Function const &_function,
		Args &&... _fcppt_untuple_args
	)
	{
		return
			fcppt::container::detail::untuple<
				Move,
				Cur + 1u,
				Size
			>::execute(
				_tuple,
				_function,
				std::forward<
					Args
				>(
					_fcppt_untuple_args
				)...,
				fcppt::move_if<
					Move
				>(
					std::get<
						Cur
					>(
						_tuple
					)
				)
			);
	}
};

}
}
}

#endif
