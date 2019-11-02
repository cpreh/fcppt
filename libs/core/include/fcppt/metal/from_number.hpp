//          Copyright Carl Philipp Reh 2009 - 2018.
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
