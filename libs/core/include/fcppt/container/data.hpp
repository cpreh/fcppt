//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_HPP_INCLUDED

#include <fcppt/container/to_pointer_type.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns a pointer the beginning of a random access container.

\ingroup fcpptcontainer

Returns a pointer the beginning of \a _container, or the null pointer if \a
_container is empty.

\tparam Container Must be a random-access container.
*/
template<
	typename Container
>
fcppt::container::to_pointer_type<
	Container
>
data(
	Container &_container
)
{
	return
		_container.empty()
		?
			nullptr
		:
			&_container[
				0
			]
		;
}

}
}

#endif
