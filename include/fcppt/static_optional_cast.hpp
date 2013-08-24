//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STATIC_OPTIONAL_CAST_HPP_INCLUDED
#define FCPPT_STATIC_OPTIONAL_CAST_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/detail/optional_cast.hpp>


namespace fcppt
{

/**
\brief Converts an optional reference using <code>static_cast</code>

\ingroup fcpptoptional

\tparam Result A non reference type of the result
\tparam Arg A non reference type of the argument

Converts \a _optional using <code>static_cast</code> to a <code>Result
&</code> if \a <code>_optional.has_value()</code> is true. Otherwise, the empty
optional will be returned.

\warning The behaviour is undefined if the <code>static_cast</code> is not well
formed.
*/
template<
	typename Result,
	typename Arg
>
fcppt::optional<
	Result &
> const
static_optional_cast(
	fcppt::optional<
		Arg &
	> const &_optional
)
{
	return
		FCPPT_DETAIL_OPTIONAL_CAST(
			fcppt::cast::static_downcast
		);
}

}

#endif
