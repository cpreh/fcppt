//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FORWARD_OPTIONAL_GET_HPP_INCLUDED
#define FCPPT_FORWARD_OPTIONAL_GET_HPP_INCLUDED

#include <fcppt/detail/forward_optional_get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Forward optional contents

\ingroup fcpptoptional

If \a Optional is an optional reference, the reference is returned. Otherwise,
if \a Optional is an rvalue, its contents are returned by moving. Otherwise,
its contents will be returned by reference.
*/
template<
	typename Optional,
	typename Arg
>
inline
decltype(
	fcppt::detail::forward_optional_get<
		Optional
	>(
		std::declval<
			Arg &
		>()
	)
)
forward_optional_get(
	Arg &_arg
)
{
	return
		fcppt::detail::forward_optional_get<
			Optional
		>(
			_arg
		);
}

}

#endif
