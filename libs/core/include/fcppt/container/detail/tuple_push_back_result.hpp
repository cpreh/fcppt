//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_TUPLE_PUSH_BACK_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

namespace detail
{

template<
	typename Tuple,
	typename NewElement
>
struct tuple_push_back_result;

template<
	typename NewElement,
	typename... Types
>
struct tuple_push_back_result<
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

#endif
