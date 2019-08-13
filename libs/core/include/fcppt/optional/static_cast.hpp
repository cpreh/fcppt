//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_STATIC_CAST_HPP_INCLUDED
#define FCPPT_OPTIONAL_STATIC_CAST_HPP_INCLUDED

#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/optional/detail/cast.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Converts an optional reference using <code>static_cast</code>

\ingroup fcpptoptional

\tparam Result A non reference type of the result
\tparam Arg A non reference type of the argument

Converts \a _optional using <code>static_cast</code> to a <code>Result
&</code> if <code>_optional.has_value()</code> is true. Otherwise, the empty
optional will be returned.

\warning The behaviour is undefined if the <code>static_cast</code> is not well
formed.
*/
template<
	typename Result,
	typename Arg
>
fcppt::optional::reference<
	Result
>
static_cast_(
	fcppt::optional::reference<
		Arg
	> const &_optional
)
{
	return
		FCPPT_OPTIONAL_DETAIL_CAST(
			fcppt::cast::static_downcast
		);
}

}
}

#endif
