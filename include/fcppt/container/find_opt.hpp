//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_FIND_OPT_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_OPT_HPP_INCLUDED

#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/deref.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns an element from a find operation or an empty optional

Searches for \a _key in the associative container \a _container. If \a _key is
found, the corresponding mapped type is returned. Otherwise, an empty optional
is returned.

\ingroup fcpptcontainer

\tparam Container Must be an associative container

\tparam Key Must be a key that can be searched for
*/
template<
	typename Container,
	typename Key
>
inline
fcppt::optional::reference<
	fcppt::container::to_value_type<
		Container
	>
>
find_opt(
	Container &_container,
	Key const &_key
)
{
	return
		fcppt::optional::deref(
			fcppt::container::find_opt_iterator(
				_container,
				_key
			)
		);
}

}
}

#endif
