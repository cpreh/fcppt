//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_OPTIONAL_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/optional/reference.hpp>
#include <fcppt/optional/detail/cast.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Converts an optional reference using <code>dynamic_cast</code>

\ingroup fcpptoptional

\tparam Result A non reference type of the result
\tparam Arg A non reference type of the argument

Converts \a _optional using <code>dynamic_cast</code> to a <code>Result
&</code> if <code>_optional.has_value()</code> is true. Otherwise, the empty
optional will be returned.

\throws std::bad_cast if the conversion cannot be done
*/
template<
	typename Result,
	typename Arg
>
fcppt::optional::reference<
	Result
>
dynamic_cast_(
	fcppt::optional::reference<
		Arg
	> const &_optional
)
{
	return
		FCPPT_OPTIONAL_DETAIL_CAST(
			dynamic_cast
		);
}

}
}

#endif
