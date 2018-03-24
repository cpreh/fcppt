//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_BRIGAND_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_BRIGAND_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/brigand/for_each_break.hpp>
#include <fcppt/type_traits/is_brigand_sequence.hpp>
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
	std::enable_if_t<
		fcppt::type_traits::is_brigand_sequence<
			Range
		>::value
	>
>
{
	template<
		typename Body
	>
	inline
	static
	void
	execute(
		Range const &,
		Body const &_body
	)
	{
		fcppt::brigand::for_each_break<
			Range
		>(
			_body
		);
	}
};

}
}

#endif
