//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

#include <fcppt/algorithm/ptr_container_erase_if.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/comparison.hpp>
#include <boost/spirit/home/phoenix/operator/self.hpp>

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
	Container &_container,
	Ptr const _element
)
{
	return
		fcppt::algorithm::ptr_container_erase_if(
			_container,
			&boost::phoenix::arg_names::arg1
			== _element
		);
}

}
}

#endif
