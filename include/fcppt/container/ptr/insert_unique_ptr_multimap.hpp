//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MULTIMAP_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_MULTIMAP_HPP_INCLUDED

#include <fcppt/type_traits/is_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace ptr
{

/**
\brief Tries to insert \p _ptr into \p _container at \p _key
\ingroup fcpptcontainerptr
\tparam PtrContainer A boost::ptr_multimap
\tparam UniquePtr A (compatible) fcppt::unique_ptr
\return
An iterator to the newly inserted position.

Transfers ownership of \p _ptr to \p _container
*/
template<
	typename PtrContainer,
	typename UniquePtr
>
typename boost::enable_if<
	fcppt::type_traits::is_unique_ptr<
		UniquePtr
	>,
	typename PtrContainer::iterator
>::type
insert_unique_ptr_multimap(
	PtrContainer &_container,
	typename PtrContainer::key_type const &_key,
	UniquePtr _ptr
)
{
	typename PtrContainer::key_type key(
		_key
	);

	return
		_container.insert(
			key,
			_ptr.release()
		);
}

}
}
}

#endif
