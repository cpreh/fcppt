//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns a pointer the beginning of a random access container

\ingroup fcpptcontainer

Returns a pointer the beginning of \a _container, or the null pointer if \a
_container is empty.

\param _container The container to return the pointer for
*/
template<
	typename Container
>
typename
boost::mpl::if_<
	std::is_const<
		Container
	>,
	typename
	Container::const_pointer,
	typename
	Container::pointer
>::type
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
