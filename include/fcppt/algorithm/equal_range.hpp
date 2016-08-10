//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED
#define FCPPT_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the equal range of a given range and a value.

\ingroup fcpptalgorithm

\tparam T Must be less-than comparable to the range's value type.
*/
template<
	typename Range,
	typename T
>
inline
boost::iterator_range<
	fcppt::container::to_iterator_type<
		typename
		std::remove_reference<
			Range
		>::type
	>
>
equal_range(
	Range &&_range,
	T const &_value
)
{
	auto const result{
		::std::equal_range(
			_range.begin(),
			_range.end(),
			_value
		)
	};

	return
		boost::make_iterator_range(
			result.first,
			result.second
		);
}

}
}

#endif
