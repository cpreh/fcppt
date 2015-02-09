//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_EXCEPTION_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>


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
	typename Type,
	typename MakeException
>
inline
Type
optional_to_exception(
	fcppt::optional<
		Type
	> const &_optional,
	MakeException const _make_exception
)
{
	if(
		_optional
	)
		return
			*_optional;

	throw
		_make_exception();
}

}

#endif
