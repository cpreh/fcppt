//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_BIT_SHIFTED_MASK_HPP_INCLUDED
#define FCPPT_BIT_SHIFTED_MASK_HPP_INCLUDED

#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/shift_count.hpp>
#include <fcppt/math/power_of_2.hpp>

namespace fcppt
{
namespace bit
{
/**
\brief A shifted mask

\ingroup fcpptbit
*/
template <typename Type>
constexpr inline fcppt::bit::mask<Type> shifted_mask(fcppt::bit::shift_count const _bits) noexcept
{
  return fcppt::bit::mask<Type>(fcppt::math::power_of_2<Type>(_bits));
}

}
}

#endif
