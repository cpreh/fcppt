//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_DETAIL_PUSH_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_DETAIL_PUSH_BACK_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace array
{
namespace detail
{

template<
	typename Array,
	typename Source,
	typename NewElement,
	std::size_t... Ints
>
inline
Array
push_back(
	std::index_sequence<
		Ints...
	>,
	Source &&_source,
	NewElement &&_new_element
)
{
	return
		Array{{
			fcppt::move_if_rvalue<
				Source
			>(
				std::get<
					Ints
				>(
					_source
				)
			)...,
			std::forward<
				NewElement
			>(
				_new_element
			)
		}};
}

}
}
}
}

#endif
