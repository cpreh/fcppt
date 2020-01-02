//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_SET_FROM_LIST_RELAXED_HPP_INCLUDED
#define FCPPT_METAL_SET_FROM_LIST_RELAXED_HPP_INCLUDED

#include <fcppt/metal/set/empty.hpp>
#include <fcppt/metal/set/insert_relaxed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace set
{

template<
	typename List
>
using
from_list_relaxed
=
::metal::accumulate<
	::metal::lambda<
		fcppt::metal::set::insert_relaxed
	>,
	fcppt::metal::set::empty,
	List
>;

}
}
}

#endif
