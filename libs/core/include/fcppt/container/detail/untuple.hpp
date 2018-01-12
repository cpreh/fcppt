//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_UNTUPLE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_UNTUPLE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Tuple,
	typename Function,
	std::size_t... Indices
>
inline
decltype(
	auto
)
untuple(
	Tuple &&_tuple,
	Function const &_function,
	std::index_sequence<
		Indices...
	>
)
{
	return
		_function(
			fcppt::move_if_rvalue<
				Tuple
			>(
				std::get<
					Indices
				>(
					_tuple
				)
			)...
		);
}

}
}
}

#endif
