//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_TO_VARARGS_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_TO_VARARGS_HPP_INCLUDED

#include <fcppt/move_if.hpp>
#include <fcppt/not.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <cstddef>
#include <tuple>
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
				fcppt::not_(
					std::is_lvalue_reference<
						Tuple
					>::value
				)
				||
				std::is_rvalue_reference<
					::brigand::at_c<
						fcppt::type_traits::remove_cv_ref_t<
							Tuple
						>,
						// TODO: Convert tuple to brigand::list
						fcppt::cast::size<
							unsigned int
						>(
							Indices
						)
					>
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

}
}
}
}

#endif
