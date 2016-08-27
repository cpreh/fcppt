//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SET_DIFFERENCE_HPP_INCLUDED
#define FCPPT_ALGORITHM_SET_DIFFERENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the difference of two sets

\ingroup fcpptalgorithm

\tparam Set Must be an associative container
*/
template<
	typename Set
>
Set
set_difference(
	Set const &_a,
	Set const &_b
)
{
	Set result;

	::std::set_difference(
		_a.begin(),
		_a.end(),
		_b.begin(),
		_b.end(),
		::std::inserter(
			result,
			result.begin()
		)
	);

	return
		result;
}

}
}

#endif
