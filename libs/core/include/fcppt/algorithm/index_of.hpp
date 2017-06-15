//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED

#include <fcppt/algorithm/find_opt.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the index of the first element found in a sequence.

\ingroup fcpptalgorithm

Searches for \a _value in \a _range and returns the index of the first
occurrence if there is any, otherwise returns the empty optional.

\tparam Range A random access range.

\tparam T A type equality-comparable to the ranges's value type.
*/
template<
	typename Range,
	typename T
>
inline
fcppt::optional::object<
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
		fcppt::optional::map(
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
