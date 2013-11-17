//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED
#define FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

template<
	typename Dest
>
typename
boost::enable_if<
	std::is_pointer<
		Dest
	>,
	Dest
>::type
from_void_ptr(
	void *const _ptr
)
{
	return
		static_cast<
			Dest
		>(
			_ptr
		);
}

template<
	typename Dest
>
inline
typename
boost::enable_if<
	std::is_pointer<
		Dest
	>,
	Dest
>::type
from_void_ptr(
	void const *const _ptr
)
{
	return
		static_cast<
			Dest
		>(
			_ptr
		);
}

}
}

#endif
