//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INSERT_HPP_INCLUDED
#define FCPPT_CONTAINER_INSERT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Inserts into an associative container.

\ingroup fcpptcontainer

\tparam Container An associative container.

\tparam Value The container's value_type.

\return Whether the value was inserted.
*/
template<
	typename Container,
	typename Value
>
[[nodiscard]]
bool
insert(
	Container &_container,
	Value &&_value
)
{
	return
		_container.insert(
			std::forward<
				Value
			>(
				_value
			)
		).second;
}

}
}

#endif
