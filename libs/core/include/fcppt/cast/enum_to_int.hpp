//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_INT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts an enum to an int

\ingroup fcpptcasts

Converts \a _enum to the integer type specified by \a Dest. This cast is unsafe
and should only be used if the enum value can be converted to the destination
type. Consider \link fcppt::cast::enum_to_underlying \endlink instead.

\tparam Dest Must be an integral type

\tparam Enum Must be an enumeration type
*/
template<
	typename Dest,
	typename Enum
>
inline
constexpr
Dest
enum_to_int(
	Enum const _enum
)
{
	static_assert(
		std::is_integral<
			Dest
		>::value
		&&
		std::is_enum<
			Enum
		>::value,
		"enum_to_int can only cast from enumerations to integers"
	);

	return
		static_cast<
			Dest
		>(
			_enum
		);
}

}
}

#endif
