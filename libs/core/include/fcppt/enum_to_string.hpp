//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_TO_STRING_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_HPP_INCLUDED

#include <fcppt/enum_to_string_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts an enum to a string.

\ingroup fcpptenum

Uses \link fcppt::enum_to_string_impl\endlink to convert an enum to a string.

\tparam Enum Must be an enum type
*/
template<
	typename Enum
>
inline
fcppt::string
enum_to_string(
	Enum const _enum
)
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enum type"
	);

	return
		fcppt::enum_to_string_impl<
			Enum
		>::get(
			_enum
		);
}

}

#endif
