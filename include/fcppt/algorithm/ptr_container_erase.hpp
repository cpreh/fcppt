//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

/// Removes pointer @a element from the ptr_container @a container 
/**
 * @return true if the element was found/erased, false otherwise
*/
template<
	typename Container,
	typename Ptr
>
bool
ptr_container_erase(
	Container &container,
	Ptr const element
)
{
	for(
		typename Container::iterator b = container.begin();
		b != container.end();
		++b
	)
	{
		if (&(*b) == element)
		{
			container.erase(b);
			return true;
		}
	}

	return false;
}

}
}

#endif
