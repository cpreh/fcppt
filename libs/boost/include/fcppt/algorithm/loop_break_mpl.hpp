//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_MPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_MPL_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/mpl/for_each_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/is_sequence.hpp>
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
		boost::mpl::is_sequence<
			typename
			std::decay<
				Range
			>::type
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
		fcppt::mpl::for_each_break<
			typename
			std::decay<
				Range
			>::type
		>(
			_body
		);
	}
};

}
}

#endif
