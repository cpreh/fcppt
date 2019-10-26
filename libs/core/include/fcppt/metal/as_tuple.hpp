//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_AS_TUPLE_HPP_INCLUDED
#define FCPPT_METAL_AS_TUPLE_HPP_INCLUDED

#include <fcppt/metal/as.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

template<
	typename List
>
using
as_tuple
=
fcppt::metal::as<
	std::tuple,
	List
>;

}
}

#endif
