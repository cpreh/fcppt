//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_MAP_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_MAP_RESULT_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/container/tuple/move_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <utility>
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
	typename Indices,
	typename Tuple,
	typename Function
>
struct map_result;

template<
	std::size_t... Indices,
	typename Tuple,
	typename Function
>
struct map_result<
	std::index_sequence<
		Indices...
	>,
	Tuple,
	Function
>
{
	using
	type
	=
	std::tuple<
		decltype(
			std::declval<
				Function
			>()(
				fcppt::move_if<
					fcppt::container::tuple::move_element<
						Tuple,
						Indices
					>::value
				>(
					std::get<
						Indices
					>(
						std::declval<
							Tuple
						>()
					)
				)
			)
		)...
	>;
};

}
}
}
}

#endif
