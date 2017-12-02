//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_TYPES_FROM_HPP_INCLUDED
#define FCPPT_ITERATOR_TYPES_FROM_HPP_INCLUDED

#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

template<
	typename Derived,
	typename Adapted
>
using
types_from
=
fcppt::iterator::types<
	Derived,
	typename
	std::iterator_traits<
		Adapted
	>::value_type,
	typename
	std::iterator_traits<
		Adapted
	>::reference,
	typename
	std::iterator_traits<
		Adapted
	>::difference_type,
	typename
	std::iterator_traits<
		Adapted
	>::iterator_category
>;

}
}

#endif
