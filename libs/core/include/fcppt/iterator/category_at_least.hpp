//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_CATEGORY_AT_LEAST_HPP_INCLUDED
#define FCPPT_ITERATOR_CATEGORY_AT_LEAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Category,
	typename CategoryRef
>
using category_at_least
=
std::is_base_of<
	CategoryRef,
	Category
>;

}
}

#endif
