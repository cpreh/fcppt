//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_FROM_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_FROM_ARRAY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/tuple/from_array_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
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
	typename Array,
	std::size_t... Indices
>
fcppt::container::tuple::from_array_result<
	Array
>
from_array(
	std::index_sequence<
		Indices...
	>,
	Array &&_source
)
{
	return
		fcppt::container::tuple::from_array_result<
			Array
		>{
			fcppt::move_if_rvalue<
				Array
			>(
				std::get<
					Indices
				>(
					_source
				)
			)...
		};
}

}
}
}
}

#endif
