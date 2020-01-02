//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_FROM_NUMBER_HPP_INCLUDED
#define FCPPT_METAL_FROM_NUMBER_HPP_INCLUDED

#include <fcppt/metal/detail/from_number.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Turns a metal::number into a std::integral_constant.

\ingroup fcpptmetal

Let <code>Number=metal::number<n></code>.
The result will be <code>std::integral_constant<Dest,n></code>.
This only works if <code>n</code> can be converted without loss into \a Dest.

\tparam Dest Must be an integral type.

\tparam Number Must be a metal::number.
*/
template<
	typename Dest,
	typename Number
>
using
from_number
=
typename
fcppt::metal::detail::from_number<
	Dest,
	Number
>::type;

}
}

#endif
