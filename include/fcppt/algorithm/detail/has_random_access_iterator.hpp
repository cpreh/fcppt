//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_HAS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_HAS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED

#include <fcppt/type_traits/is_random_access_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Type
>
using
has_random_access_iterator
=
fcppt::type_traits::is_random_access_iterator<
	decltype(
		std::declval<
			Type
		>().begin()
	)
>;

}
}
}

#endif
