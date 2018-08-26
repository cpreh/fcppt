//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_FROM_HPP_INCLUDED
#define FCPPT_OPTIONAL_FROM_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
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
std::result_of_t<
	Default()
>
from(
	Optional &&_optional,
	Default const _default
)
{
	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value,
		"Optional must be an optional"
	);

	return
		_optional.has_value()
		?
			fcppt::move_if_rvalue<
				Optional
			>(
				_optional.get_unsafe()
			)
		:
			_default()
		;
}

}
}

#endif
