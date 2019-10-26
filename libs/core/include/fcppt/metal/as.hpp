//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_AS_HPP_INCLUDED
#define FCPPT_METAL_AS_HPP_INCLUDED

#include <fcppt/metal/detail/as.hpp>


namespace fcppt
{
namespace metal
{

template<
	template<
		typename ...
	> class Type,
	typename List
>
using
as
=
typename
fcppt::metal::detail::as<
	Type,
	List
>::type;

}
}

#endif
