//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IF_NOT_LAST_INDEX_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IF_NOT_LAST_INDEX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Index,
	typename Size,
	typename Function
>
inline
typename
std::enable_if<
	Index::value
	!=
	Size::value - 1u,
	void
>::type
if_not_last_index(
	Index,
	Size,
	Function const &_function
)
{
	_function();
}

template<
	typename Index,
	typename Size,
	typename Function
>
inline
typename
std::enable_if<
	Index::value
	==
	Size::value - 1u,
	void
>::type
if_not_last_index(
	Index,
	Size,
	Function const &
)
{
}

}
}
}

#endif
