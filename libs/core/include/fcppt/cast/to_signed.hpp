//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_SIGNED_HPP_INCLUDED
#define FCPPT_CAST_TO_SIGNED_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts an unsigned int to its signed type

\ingroup fcpptcasts

Converts \a _value to its signed type. This cast is unsafe and should only be
used if \a _value fits into the result.

\tparam Type Must be an unsigned type
*/
template<
	typename Type
>
inline
constexpr
std::make_signed_t<
	Type
>
to_signed(
	Type const _value
)
noexcept
{
	static_assert(
		std::is_unsigned<
			Type
		>::value,
		"to_signed can only cast from unsigned types"
	);

	return
		static_cast<
			std::make_signed_t<
				Type
			>
		>(
			_value
		);
}

}
}

#endif
