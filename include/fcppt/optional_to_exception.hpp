//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/forward_optional_get.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/detail/check_optional.hpp>


namespace fcppt
{

/**
\brief Returns the value contained in an optional or throws an exception

\ingroup fcpptoptional

If \a _optional is set to x, then x is returned. Otherwise, the result of \a
_make_exception is thrown as an exception.

\tparam MakeException Must be a nullary function returning an object type
*/
template<
	typename Optional,
	typename MakeException
>
inline
decltype(
	fcppt::forward_optional_get<
		Optional
	>(
		std::declval<
			Optional
		>().get_unsafe()
	)
)
optional_to_exception(
	Optional &&_optional,
	MakeException const _make_exception
)
{
	static_assert(
		fcppt::detail::check_optional<
			Optional
		>::value,
		"Optional must be an optional"
	);


	if(
		_optional.has_value()
	)
		return
			fcppt::forward_optional_get<
				Optional
			>(
				_optional.get_unsafe()
			);

	throw
		_make_exception();
}

}

#endif
