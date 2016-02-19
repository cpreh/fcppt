//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED
#define FCPPT_CAST_ENUM_TO_UNDERLYING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts an enum to its underlying type

\ingroup fcpptcasts

Converts \a _enum to its underlying integer type.

\tparam Enum Must be an enumeration type
*/
template<
	typename Enum
>
inline
constexpr
typename
std::underlying_type<
	Enum
>::type
enum_to_underlying(
	Enum const _enum
)
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enumeration type"
	);

	return
		static_cast<
			typename
			std::underlying_type<
				Enum
			>::type
		>(
			_enum
		);
}

}
}

#endif
