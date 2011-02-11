//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

#include <fcppt/algorithm/ptr_container_erase_if.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/object/static_cast.hpp>
#include <boost/spirit/home/phoenix/operator/comparison.hpp>
#include <boost/spirit/home/phoenix/operator/self.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace algorithm
{

/// Removes pointer @a _element from the ptr_container @a _container 
/**
 * @type Ptr may be @type Container::value_type or a const version of it
 * @return true if the element was found/erased, false otherwise
*/
template<
	typename Container,
	typename Ptr
>
typename boost::enable_if<
	boost::is_same<
		typename boost::add_pointer<
			typename boost::remove_const<
				typename boost::remove_pointer<
					Ptr
				>::type
			>::type
		>::type,
		typename Container::value_type
	>,
	bool
>::type
ptr_container_erase(
	Container &_container,
	Ptr const _element
)
{
	return
		fcppt::algorithm::ptr_container_erase_if(
			_container,
			boost::phoenix::static_cast_<
				Ptr
			>(
				&boost::phoenix::arg_names::arg1
			)
			== _element
		);
}

}
}

#endif
