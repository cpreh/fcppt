//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_INDEX_OF_ENUM_ARRAY_HPP_INCLUDED
#define FCPPT_ALGORITHM_INDEX_OF_ENUM_ARRAY_HPP_INCLUDED

#include <fcppt/algorithm/index_of.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/container/enum_array_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Returns the enum of the first element found in an enum array

\ingroup fcpptalgorithm

Searches for \a _value in \a _array and returns the index of the first
occurrence as an enum iff there is any.
*/
template<
	typename Enum,
	typename Value
>
inline
fcppt::optional::object<
	Enum
>
index_of_enum_array(
	fcppt::container::enum_array<
		Enum,
		Value
	> const &_array,
	Value const &_value
)
{
	return
		fcppt::optional::map(
			fcppt::algorithm::index_of(
				_array,
				_value
			),
			[](
				typename
				fcppt::container::enum_array<
					Enum,
					Value
				>::size_type const _index
			)
			{
				return
					fcppt::cast::int_to_enum<
						Enum
					>(
						_index
					);
			}
		);
}

}
}

#endif
