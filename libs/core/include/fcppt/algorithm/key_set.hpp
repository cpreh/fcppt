//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED
#define FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED

#include <fcppt/algorithm/map.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Creates a set of keys from a map.

Inserts every key from \a _map into the resulting set.

\tparam Map A map-like container.

\tparam Set A set-like container.
*/
template<
	typename Set,
	typename Map
>
inline
Set
key_set(
	Map const &_map
)
{
	return
		fcppt::algorithm::map<
			Set
		>(
			_map,
			[](
				typename
				Map::const_reference _item
			)
			{
				return
					_item.first;
			}
		);
}

}
}

#endif
