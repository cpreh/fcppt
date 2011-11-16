//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DATA_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_HPP_INCLUDED

namespace fcppt
{
namespace container
{

/** 
 * FIXME 
 * \ingroup fcpptcontainer
 */
template<
	typename Container
>
typename Container::pointer
data(
	Container &_container
)
{
	return
		_container.empty()
		?
			0
		:
			&_container[0]
		;
}

/**
 * FIXME
 * \ingroup fcpptcontainer
 */
template<
	typename Container
>
typename Container::const_pointer
data(
	Container const &_container
)
{
	return
		_container.empty()
		?
			0
		:
			&_container[0]
		;
}

}
}

#endif
