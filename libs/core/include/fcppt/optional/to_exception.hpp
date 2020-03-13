//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>


namespace fcppt
{
namespace optional
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
auto
to_exception(
	Optional &&_optional,
	MakeException const _make_exception
)
->
decltype(
	fcppt::move_if_rvalue<
		Optional
	>(
		_optional.get_unsafe()
	)
)
{
	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"Optional must be an optional"
	);


	if(
		_optional.has_value()
	)
	{
		return
			fcppt::move_if_rvalue<
				Optional
			>(
				_optional.get_unsafe()
			);
	}

	throw
		_make_exception();
}

}
}

#endif
