//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_AS_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_AS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal/list/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	template<
		typename ...
	> class Type,
	typename List
>
struct as;

template<
	template<
		typename ...
	> class Type,
	typename... Elements
>
struct as<
	Type,
	::metal::list<
		Elements...
	>
>
{
	typedef
	Type<
		Elements...
	>
	type;
};

}
}
}

#endif
