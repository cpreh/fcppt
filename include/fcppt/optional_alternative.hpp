//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED
#define FCPPT_OPTIONAL_ALTERNATIVE_HPP_INCLUDED

#include <fcppt/detail/check_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Returns the first optional if it is not nothing

\ingroup fcpptoptional

If \a _optional1 is not nothing, it returns \a _optional1, otherweise \a _optional2.
*/
template<
	typename Optional
>
Optional
optional_alternative(
	Optional &&_optional1,
	Optional &&_optional2
)
{
	static_assert(
		fcppt::detail::check_optional<
			Optional
		>::value,
		"optional_alternative must return an optional"
	);

	return
		std::forward<
			Optional
		>(
			_optional1.has_value()
			?
				_optional1
			:
				_optional2
		);
}

}

#endif
