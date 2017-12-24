//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_FOLD_TUPLE_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_FOLD_TUPLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

template<
	typename Element,
	typename Tuple
>
struct fold_tuple;

template<
	typename Element,
	typename... Types
>
struct fold_tuple<
	Element,
	std::tuple<
		Types...
	>
>
{
	typedef
	std::tuple<
		Types...,
		Element
	>
	type;
};

}
}
}

#endif
