//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_INIT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Array,
	typename Function,
	std::size_t... Ints
>
inline
Array
array_init(
	std::index_sequence<
		Ints...
	>,
	Function const &_function
)
{
	return
		Array{{
			_function(
				std::integral_constant<
					std::size_t,
					Ints
				>{}
			)...
		}};
}

}
}
}

#endif
