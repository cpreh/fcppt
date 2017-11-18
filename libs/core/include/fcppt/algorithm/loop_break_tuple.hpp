//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_TUPLE_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_TUPLE_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/algorithm/detail/tuple_loop_break.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

template<
	typename Range
>
struct loop_break_impl<
	Range,
	typename
	std::enable_if<
		fcppt::type_traits::is_std_tuple<
			typename
			std::decay<
				Range
			>::type
		>::value
	>::type
>
{
	template<
		typename Body
	>
	inline
	static
	void
	execute(
		Range &&_range,
		Body const &_body
	)
	{
		fcppt::algorithm::detail::tuple_loop_break<
			0u
		>(
			std::forward<
				Range
			>(
				_range
			),
			_body
		);
	}
};

}
}

#endif
