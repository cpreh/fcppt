//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_TYPES_OF_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_TYPES_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal/list/list.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{
namespace detail
{

template<
	typename Type
>
struct types_of;

template<
	typename... Types
>
struct types_of<
	std::tuple<
		Types...
	>
>
{
	typedef
	::metal::list<
		Types...
	>
	type;
};

}
}
}
}

#endif
