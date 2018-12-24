//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_COMBINE_TUPLES_HPP_INCLUDED
#define FCPPT_PARSE_COMBINE_TUPLES_HPP_INCLUDED

#include <fcppt/parse/detail/flatten_tuples.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Left,
	typename Right
>
// TODO: Better type
auto
combine_tuples(
	Left &&_left,
	Right &&_right
)
{
	return
		fcppt::parse::detail::flatten_tuples(
			std::forward<
				Left
			>(
				_left
			),
			std::forward<
				Right
			>(
				_right
			)
		);
}

}
}

#endif
