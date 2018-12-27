//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_CONTAINS_HPP_INCLUDED
#define FCPPT_CONTAINER_CONTAINS_HPP_INCLUDED


namespace fcppt
{
namespace container
{

/**
\brief Checks if a container has a key.

\ingroup fcpptcontainer

\tparam Container Must be a container with the <code>count</code> function.
*/
template<
	typename Container
>
inline
bool
contains(
	Container const &_container,
	typename Container::key_type const &_key
)
{
	return
		_container.count(
			_key
		)
		> 0u;
}

}
}

#endif
