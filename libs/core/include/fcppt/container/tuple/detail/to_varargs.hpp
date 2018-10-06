//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_TO_VARARGS_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_TO_VARARGS_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/container/tuple/move_element.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4702)

template<
	typename Tuple,
	typename Function,
	std::size_t... Indices
>
inline
decltype(
	auto
)
to_varargs(
	Tuple &&_tuple,
	Function const &_function,
	std::index_sequence<
		Indices...
	>
)
{
	return
		_function(
			fcppt::move_if<
				fcppt::container::tuple::move_element<
					Tuple,
					Indices
				>::value
			>(
				std::get<
					Indices
				>(
					_tuple
				)
			)...
		);
}

FCPPT_PP_POP_WARNING

}
}
}
}

#endif
