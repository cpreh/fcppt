//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_FIND_BY_RESULT_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_FIND_BY_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename In,
	typename Func
>
using
find_by_result
=
typename
std::result_of<
	Func(
		typename
		std::iterator_traits<
			In
		>::reference
	)
>::type;

}
}
}

#endif
