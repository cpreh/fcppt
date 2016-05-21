//          Copyright Carl Philipp Reh 2009 - 2016.
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
optional value if it failed

\ingroup fcpptcasts

This cast is the same as \link fcppt::cast::dynamic \endlink but only works
on unrelated types.
*/
template<
	typename Derived,
	typename Base
>
inline
fcppt::optional::reference<
	Derived
>
dynamic_cross(
	Base &_base
)
{
	static_assert(
		!fcppt::type_traits::is_base_of<
			typename
			std::remove_cv<
				Base
			>::type,
			typename
			std::decay<
				Derived
			>::type
		>::value,
		"dynamic_cross can only be used on unrelated types"
	);

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
