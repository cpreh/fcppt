//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MOVE_IF_HPP_INCLUDED
#define FCPPT_DETAIL_MOVE_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	bool Cond
>
struct move_if;

template<>
struct move_if<
	false
>
{
	template<
		typename Arg
	>
	inline
	static
	Arg &
	execute(
		Arg &_arg
	)
	{
		return
			_arg;
	}
};

template<>
struct move_if<
	true
>
{
	template<
		typename Arg
	>
	inline
	static
	Arg &&
	execute(
		Arg &_arg
	)
	{
		return
			std::move(
				_arg
			);
	}
};

}
}

#endif
