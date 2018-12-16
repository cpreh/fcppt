//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_DETAIL_IS_SET_HPP_INCLUDED
#define FCPPT_BRIGAND_DETAIL_IS_SET_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/is_set.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{
namespace detail
{

template<
	typename
>
struct is_set;

template<
	typename... Types
>
struct is_set<
	::brigand::list<
		Types...
	>
>
:
::brigand::is_set<
	Types...
>
{
};

}
}
}

#endif
