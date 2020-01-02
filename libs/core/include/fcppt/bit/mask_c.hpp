//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BIT_MASK_C_HPP_INCLUDED
#define FCPPT_BIT_MASK_C_HPP_INCLUDED

#include <fcppt/bit/mask.hpp>


namespace fcppt
{
namespace bit
{

/**
\brief A bit mask from an integral constant

\ingroup fcpptbit
*/
template<
	typename Type,
	Type Mask
>
constexpr
inline
fcppt::bit::mask<
	Type
>
mask_c()
noexcept
{
	return
		fcppt::bit::mask<
			Type
		>(
			Mask
		);
}

}
}

#endif
