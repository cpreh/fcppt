//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BIT_SHIFTED_MASK_C_HPP_INCLUDED
#define FCPPT_BIT_SHIFTED_MASK_C_HPP_INCLUDED

#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/shift_count.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace bit
{

/**
\brief A constant shifted mask

\ingroup fcpptbit
*/
template<
	typename Type,
	fcppt::bit::shift_count Bits
>
constexpr
inline
fcppt::bit::mask<
	Type
>
shifted_mask_c()
noexcept
{
	static_assert(
		Bits
		<
		std::numeric_limits<
			Type
		>::digits,
		"Bits out of range"
	);

	return
		fcppt::bit::shifted_mask<
			Type
		>(
			Bits
		);
}

}
}

#endif
