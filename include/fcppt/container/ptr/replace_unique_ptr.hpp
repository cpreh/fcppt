//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_PTR_REPLACE_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_CONTAINER_PTR_REPLACE_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/type_traits/is_unique_ptr.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace container
{
namespace ptr
{
template
<
	typename PtrContainer,
	typename UniquePtr
>
typename 
boost::enable_if
<
	fcppt::type_traits::is_unique_ptr<UniquePtr>,
	void
>::type
replace_unique_ptr(
	PtrContainer &_container,
	typename PtrContainer::size_type const _index,
	UniquePtr _ptr)
{
	_container.replace(
		_index,
		_ptr.release());
}
}
}
}

#endif
