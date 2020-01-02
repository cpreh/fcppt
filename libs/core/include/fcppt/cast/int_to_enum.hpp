//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_INT_TO_ENUM_HPP_INCLUDED
#define FCPPT_CAST_INT_TO_ENUM_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts an int to an enum

\ingroup fcpptcasts

Converts the integer \a _source to the enum type specified by \a Enum. This
cast is unsafe and should only be used if the enum can actually hold the
integer value. Consider using fcppt::cast_to_enum instead.

\tparam Source Must be an integral type

\tparam Enum Must be an enumeration type
*/
template<
	typename Enum,
	typename Source
>
inline
constexpr
Enum
int_to_enum(
	Source const _source
)
noexcept
{
	static_assert(
		std::is_enum_v<
			Enum
		>
		&&
		std::is_integral_v<
			Source
		>,
		"int_to_enum can only cast from integral types to enumerations"
	);

	return
		static_cast<
			Enum
		>(
			_source
		);
}

}
}

#endif
