//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_SET_INSERT_HPP_INCLUDED
#define FCPPT_METAL_SET_INSERT_HPP_INCLUDED

#include <fcppt/unit.hpp>
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
	typename Set,
	typename Key
>
using
insert
=
::metal::insert_key<
	Set,
	Key,
	fcppt::unit
>;

}
}
}

#endif
