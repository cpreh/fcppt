//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_PUSH_FRONT_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_PUSH_FRONT_UNIQUE_PTR_HPP_INCLUDED

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

/// Tries to push_front @a _ptr into @a _container
/**
 * Transfers ownership of @a _ptr to @a _container
*/
template<
	typename PtrContainer,
	typename UniquePtr
>
typename boost::enable_if<
	fcppt::type_traits::is_unique_ptr<
		UniquePtr
	>,
	void
>::type
push_front_unique_ptr(
	PtrContainer &_container,
	UniquePtr _ptr
)
{
	_container.push_front(
		_ptr.release()
	);
}

}
}
}

#endif
