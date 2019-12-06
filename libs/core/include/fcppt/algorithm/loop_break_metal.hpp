//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_METAL_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_METAL_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/metal/for_each_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
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
		::metal::is_list<
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
		fcppt::metal::for_each_break<
			Range
		>(
			_body
		);
	}
};

}
}

#endif
