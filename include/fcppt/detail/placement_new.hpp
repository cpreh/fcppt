//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_PLACEMENT_NEW_HPP_INCLUDED
#define FCPPT_DETAIL_PLACEMENT_NEW_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <new>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
inline
void
placement_new(
	void *const _store,
	Type &&_value
)
{
	new (
		_store
	)
	typename
	std::decay<
		Type
	>::type(
		std::forward<
			Type
		>(
			_value
		)
	);
}

}
}

#endif
