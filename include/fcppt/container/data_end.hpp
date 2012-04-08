//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_END_HPP_INCLUDED

#include <fcppt/container/detail/data_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns a pointer one past the end of a random access container

\ingroup fcpptcontainer

Returns a pointer one past the end of \a _container, or the null pointer if \a
_container is empty.

\param _container The container to return the pointer for
*/
template<
	typename Container
>
typename Container::pointer
data_end(
	Container &_container
)
{
	return
		container::detail::data_end<
			typename Container::pointer
		>(
			_container
		);
}

/**
\brief Returns a const_pointer one past the end of a random access container

\ingroup fcpptcontainer

Returns a const_pointer one past the end of \a _container, or the null pointer
if \a _container is empty.

\param _container The container to return the const_pointer for
*/
template<
	typename Container
>
typename Container::const_pointer
data_end(
	Container const &_container
)
{
	return
		container::detail::data_end<
			typename Container::const_pointer
		>(
			_container
		);
}

}
}

#endif
