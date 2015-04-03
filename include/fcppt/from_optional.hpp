//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>


namespace fcppt
{

/**
\brief Returns the value contained in an optional or a default value

\ingroup fcpptoptional

If \a _optional is set to x, then x is returned. Otherwise, the result of \a
_default is returned.

\tparam Func Must be a function of type <code>Type ()</code>
*/
template<
	typename Type,
	typename Func
>
Type
from_optional(
	fcppt::optional<
		Type
	> const &_optional,
	Func const _default
)
{
	return
		_optional
		?
			_optional.get_unsafe()
		:
			_default()
		;
}

}

#endif
