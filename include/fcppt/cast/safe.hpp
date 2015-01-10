//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_SAFE_HPP_INCLUDED
#define FCPPT_CAST_SAFE_HPP_INCLUDED

#include <fcppt/cast/detail/safe.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief A cast that prohibits lossy conversions

\ingroup fcpptcasts

This cast implicitly converts arithmetic types like fcppt::cast::safe_numeric
does. For every other type the conversion is also done implicitly but without
any further restrictions. In general, this means that either the restrictions
of fcppt::cast::safe_numeric must hold or \a Source must be implicitly
convertible to \a Dest.

\tparam Dest Can be any type

\tparam Source Can be any type

\param _source The source of the conversion

\return The implicitly converted value
*/
template<
	typename Dest,
	typename Source
>
Dest
safe(
	Source const &_source
)
{
	return
		fcppt::cast::detail::safe<
			Dest
		>(
			_source
		);
}

}
}

#endif
