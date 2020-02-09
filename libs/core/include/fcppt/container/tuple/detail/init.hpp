//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
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
	typename Tuple,
	typename Function,
	std::size_t... Ints
>
inline
Tuple
init(
	std::index_sequence<
		Ints...
	>,
	Function const &_function
)
{
	return
		Tuple{
			_function(
				std::integral_constant<
					std::size_t,
					Ints
				>{}
			)...
		};
}

}
}
}
}

#endif
