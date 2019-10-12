//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_SET_FROM_LIST_HPP_INCLUDED
#define FCPPT_METAL_SET_FROM_LIST_HPP_INCLUDED

#include <fcppt/metal/set/insert_key_relaxed.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/accumulate.hpp>
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
from_list
=
::metal::accumulate<
	::metal::lambda<
		fcppt::metal::set::insert_key_relaxed
	>,
	fcppt::metal::set::make<>,
	List
>;

}
}
}

#endif
