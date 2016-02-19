//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_GENERATE_N_HPP_INCLUDED
#define FCPPT_ALGORITHM_GENERATE_N_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Generates a container by calling a function a number of times

\ingroup fcpptalgorithm

Calls \a _function \a _count times and collects the results into a container.

\tparam Function A function callable as <code>TargetContainer::value_type()</code>.
*/
template<
	typename TargetContainer,
	typename Function
>
TargetContainer
generate_n(
	std::size_t const _count,
	Function const &_function
)
{
	return
		fcppt::algorithm::map<
			TargetContainer
		>(
			fcppt::make_int_range_count(
				_count
			),
			[
				&_function
			](
				std::size_t
			)
			{
				return
					_function();
			}
		);
}

}
}

#endif
