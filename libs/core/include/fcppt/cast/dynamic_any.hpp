//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_ANY_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_ANY_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts between references using <code>dynamic_cast</code>, returning an empty optional on failure

\ingroup fcpptcasts

Tries to cast \a _src to \a Dest using <code>dynamic_cast</code>. On failure,
an empty optional is returned.

\tparam Derived The type to cast to. Can be cv-qualified.

\tparam Base A cv-qualified non-reference type.
*/
template<
	typename Derived,
	typename Base
>
inline
fcppt::optional::reference<
	Derived
>
dynamic_any(
	Base &_base
)
noexcept
{
	return
		fcppt::cast::detail::dynamic<
			Derived
		>(
			_base
		);
}

}
}

#endif
