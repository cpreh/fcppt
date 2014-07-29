//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>


namespace fcppt
{

/**
\brief Return the value contained in an optional or a default value

\ingroup fcpptoptional
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
			*_optional
		:
			_default()
		;
}

}

#endif
