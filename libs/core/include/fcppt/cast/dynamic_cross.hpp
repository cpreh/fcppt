//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_CROSS_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_CROSS_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Tries a <code>dynamic_cast</code> on unrelated types, returning an empty
optional on failure

\ingroup fcpptcasts

This cast is the same as \link fcppt::cast::dynamic \endlink but only works
on unrelated types.

Here is an example:

\snippet cast/dynamic_cross.cpp dynamic_cross

\tparam Dest The type to cast to. Can be cv-qualified. Must not inherit from \a Base.

\tparam Src A cv-qualified non-reference type.

\see \link fcppt::cast::dynamic \endlink
*/
template<
	typename Dest,
	typename Src
>
inline
fcppt::optional::reference<
	Dest
>
dynamic_cross(
	Src &_src
)
noexcept
{
	static_assert(
		!fcppt::type_traits::is_base_of<
			std::remove_cv_t<
				Src
			>,
			std::remove_cv_t<
				Dest
			>
		>::value,
		"dynamic_cross can only be used on unrelated types"
	);

	return
		fcppt::cast::detail::dynamic<
			Dest
		>(
			_src
		);
}

}
}

#endif
