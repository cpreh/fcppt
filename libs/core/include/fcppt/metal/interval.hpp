//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_INTERVAL_HPP_INCLUDED
#define FCPPT_METAL_INTERVAL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <fcppt/metal/detail/interval.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

template<
	typename Type,
	Type Begin,
	Type End
>
using
interval
=
typename
fcppt::metal::detail::interval<
	Type,
	Begin,
	End
>::type;

}
}

#endif
