//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MAP_VALUES_COPY_HPP_INCLUDED
#define FCPPT_CONTAINER_MAP_VALUES_COPY_HPP_INCLUDED

#include <fcppt/algorithm/map.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Copies the mapped values of an associative container into a container.

\ingroup fcpptcontainer

\tparam Result A sequence container of <code>Map::mapped_type</code>.

\tparam Map An associative container.
*/
template<
	typename Result,
	typename Map
>
Result
map_values_copy(
	Map const &_map
)
{
	return
		fcppt::algorithm::map<
			Result
		>(
			_map,
			[](
				auto const &_element
			)
			{
				return
					_element.second;
			}
		);
}

}
}

#endif
