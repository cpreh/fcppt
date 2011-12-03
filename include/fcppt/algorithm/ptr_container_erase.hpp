//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED
#define FCPPT_ALGORITHM_PTR_CONTAINER_ERASE_HPP_INCLUDED

#include <fcppt/algorithm/ptr_container_erase_if.hpp>
#include <fcppt/algorithm/detail/ptr_container_erase_pred.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Removes pointer \p _element from the ptr_container \p _container
 * \ingroup fcpptalgorithm
 * \tparam Ptr May be <code>Container::value_type</code> or a const version of it
 * \return <code>true</code> if the element was found/erased, <code>false</code> otherwise
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
			fcppt::algorithm::detail::ptr_container_erase_pred<
				Ptr
			>(
				_element
			)
		);
}

}
}

#endif
