//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_IS_ASSOCIATIVE_HPP_INCLUDED
#define FCPPT_CONTAINER_IS_ASSOCIATIVE_HPP_INCLUDED

// TODO: somehow forward declare this!
#include <fcppt/container/map_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <set>
#include <map>

namespace fcppt
{
namespace container
{

template<
	typename T
>
struct is_associative
:
boost::false_type
{};

template<
	typename Key,
	typename Mapped,
	typename Compare,
	typename Alloc
>
struct is_associative<
	std::map<
		Key,
		Mapped,
		Compare,
		Alloc
	>
>
:
boost::true_type
{};

template<
	typename Value,
	typename Compare,
	typename Alloc
>
struct is_associative<
	std::set<
		Value,
		Compare,
		Alloc
	>
>
:
boost::true_type
{};

template<
	typename MapType
>
struct is_associative<
	container::map<
		MapType
	>
>
:
boost::true_type
{};

}
}

#endif
