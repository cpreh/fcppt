//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_PUSH_BACK_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_PUSH_BACK_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
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
	typename Tuple,
	typename NewElement
>
struct push_back_result;

template<
	typename NewElement,
	typename... Types
>
struct push_back_result<
	std::tuple<
		Types...
	>,
	NewElement
>
{
	typedef
	std::tuple<
		Types...,
		NewElement
	>
	type;
};

}
}
}
}

#endif
