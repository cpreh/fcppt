//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

template<
	typename Container,
	typename Ptr
>
bool
ptr_container_erase(
	Container &c,
	Ptr const s
)
{
	for(
		typename Container::iterator b = c.begin();
		b != c.end();
		++b
	)
	{
		if (&(*b) == s)
		{
			c.erase(b);
			return true;
		}
	}

	return false;
}

}
}

#endif
