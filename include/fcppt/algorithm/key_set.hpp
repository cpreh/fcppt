//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED
#define FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Creates a set of keys from a map

Inserts every key from \a map into the resulting set.
*/
template<
	typename Set,
	typename Map
>
Set
key_set(
	Map const &_map
)
{
	Set ret;

	for(
		typename Map::const_reference item
		:
		_map
	)
		ret.insert(
			item.first
		);

	return
		std::move(
			ret
		);
}

}
}

#endif
