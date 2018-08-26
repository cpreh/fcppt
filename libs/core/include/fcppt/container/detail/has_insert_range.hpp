//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_HAS_INSERT_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_HAS_INSERT_RANGE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Type,
	typename Test = void
>
struct has_insert_range
:
std::false_type
{
};

template<
	typename Type
>
struct has_insert_range<
	Type,
	decltype(
		std::declval<
			Type
		>().insert(
			std::declval<
				typename
				Type::iterator
			>(),
			std::declval<
				typename
				Type::iterator
			>()
		)
	)
>
:
std::true_type
{
};

}
}
}

#endif
