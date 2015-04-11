//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_OPTIONAL_HPP_INCLUDED
#define FCPPT_FROM_OPTIONAL_HPP_INCLUDED

#include <fcppt/forward_optional_get.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/detail/check_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Returns the value contained in an optional or a default value

\ingroup fcpptoptional

If \a _optional is set to x, then x is returned. Otherwise, the result of \a
_default is returned.

\tparam Default Must be a function of type <code>Optional::value_type ()</code>
*/
template<
	typename Optional,
	typename Default
>
typename
std::result_of<
	Default()
>::type
from_optional(
	Optional &&_optional,
	Default const _default
)
{
	static_assert(
		fcppt::detail::check_optional<
			Optional
		>::value,
		"Optional must be an optional"
	);

	return
		_optional.has_value()
		?
			fcppt::forward_optional_get<
				Optional
			>(
				_optional.get_unsafe()
			)
		:
			_default()
		;
}

}

#endif
