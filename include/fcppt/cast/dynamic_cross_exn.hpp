//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_CROSS_EXN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_CROSS_EXN_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic_exn.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts between references of unrelated types using
<code>dynamic_cast</code> and provides additional error information

\ingroup fcpptcasts

This cast is the same as \link fcppt::cast::dynamic_exn \endlink but only works
on unrelated types.

\see fcppt::cast::dynamic_exn
*/
template<
	typename Dest,
	typename Src
>
inline
typename
std::enable_if<
	std::is_reference<
		Dest
	>::value,
	Dest
>::type
dynamic_cross_exn(
	Src &_src
)
{
	static_assert(
		!fcppt::type_traits::is_base_of<
			typename
			std::remove_cv<
				Src
			>::type,
			typename
			std::decay<
				Dest
			>::type
		>::value,
		"dynamic_cross_exn can only be used on unrelated types"
	);

	return
		fcppt::cast::detail::dynamic_exn<
			Dest
		>(
			_src
		);
}

}
}

#endif
