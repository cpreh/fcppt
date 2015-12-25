//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_map.hpp>
#include <fcppt/algorithm/find_opt.hpp>
#include <fcppt/cast/to_unsigned.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the index of the first element found in a sequence

\ingroup fcpptalgorithm

Searches for \a _value in \a _range and returns the index of the first
occurrence iff there is any.

\tparam Range A random access range

\tparam T A type comparable to the iterator's value type
*/
template<
	typename Range,
	typename T
>
inline
fcppt::optional<
	typename
	Range::size_type
>
index_of(
	Range const &_range,
	T const &_value
)
{
	typedef
	typename
	Range::const_iterator
	iterator_type;

	iterator_type const beg(
		_range.begin()
	);

	return
		fcppt::optional_map(
			fcppt::algorithm::find_opt(
				_range,
				_value
			),
			[
				beg
			](
				iterator_type const _it
			)
			{
				return
					fcppt::cast::to_unsigned(
						_it
						-
						beg
					);
			}
		);
}

}
}

#endif
