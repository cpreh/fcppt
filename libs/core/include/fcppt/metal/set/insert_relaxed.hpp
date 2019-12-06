//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_SET_INSERT_RELAXED_HPP_INCLUDED
#define FCPPT_METAL_SET_INSERT_RELAXED_HPP_INCLUDED

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/insert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
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
insert_relaxed
=
::metal::invoke<
	::metal::if_<
		fcppt::metal::set::contains<
			Set,
			Key
		>,
		::metal::always<
			Set
		>,
		::metal::bind<
			::metal::lambda<
				fcppt::metal::set::insert
			>,
			::metal::always<
				Set
			>,
			::metal::always<
				Key
			>
		>
	>
>;

}
}
}

#endif
