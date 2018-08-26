//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED
#define FCPPT_ALGORITHM_EQUAL_RANGE_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/iterator/range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
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
fcppt::iterator::range<
	fcppt::container::to_iterator_type<
		std::remove_reference_t<
			Range
		>
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
		fcppt::iterator::make_range(
			result.first,
			result.second
		);
}

}
}

#endif
