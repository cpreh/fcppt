//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_INSERT_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace ptr
{

/**
\brief Tries to insert \p _ptr into \p _container at \p _iterator
\ingroup fcpptcontainerptr
\tparam PtrContainer A pointer container
\tparam Type The type the unique_ptr is holding
\return An iterator to the newly inserted position

Transfers ownership of \p _ptr to \p _container
*/
template<
	typename PtrContainer,
	typename Type
>
typename PtrContainer::iterator
insert_unique_ptr(
	PtrContainer &_container,
	typename PtrContainer::iterator const _iterator,
	std::unique_ptr<
		Type
	> _ptr
)
{
	return
		_container.insert(
			_iterator,
			_ptr.release()
		);
}

}
}
}

#endif
