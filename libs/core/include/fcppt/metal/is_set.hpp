//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_IS_SET_HPP_INCLUDED
#define FCPPT_METAL_IS_SET_HPP_INCLUDED

#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/metal/set/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

template<
	typename List
>
using
is_set
=
std::is_same<
	::metal::size<
		List
	>,
	fcppt::metal::set::size<
		fcppt::metal::set::from_list_relaxed<
			List
		>
	>
>;

}
}

#endif
