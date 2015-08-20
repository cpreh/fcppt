//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_INDEX_OF_HPP_INCLUDED

#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/algorithm/find_opt.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the index of the first element found in a sequence

\ingroup fcpptalgorithm

Searches for \a _value in the sequence <code>[_beg,_end)</code> and returns the
index of the first occurrence iff there is any.

\tparam In A forward iterator

\tparam T A type compatible with the iterator's value type
*/
template<
	typename In,
	typename T
>
inline
fcppt::optional<
	typename
	std::iterator_traits<
		In
	>::difference_type
>
index_of(
	In const _beg,
	In const _end,
	T const &_value
)
{
	return
		fcppt::optional_bind_construct(
			fcppt::algorithm::find_opt(
				_beg,
				_end,
				_value
			),
			[
				_beg
			](
				In const _it
			)
			{
				return
					std::distance(
						_beg,
						_it
					);
			}
		);
}

template<
	typename Container,
	typename T
>
inline
fcppt::optional<
	typename
	Container::size_type
>
index_of(
	Container const &_container,
	T const &_value
)
{
	return
		fcppt::optional_bind_construct(
			fcppt::algorithm::index_of(
				_container.begin(),
				_container.end(),
				_value
			),
			[](
				typename
				Container::difference_type const _diff
			)
			{
				return
					fcppt::cast::to_unsigned(
						_diff
					);
			}
		);
}

}
}

#endif
