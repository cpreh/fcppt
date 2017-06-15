//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
inline
bool
array_less(
	T const &_a,
	T const &_b
)
{
	typedef
	typename
	T::storage_type
	storage_type;

	storage_type const &storage_a(
		_a.storage()
	);

	storage_type const &storage_b(
		_b.storage()
	);

	return
		std::lexicographical_compare(
			storage_a.begin(),
			storage_a.end(),
			storage_b.begin(),
			storage_b.end()
		);
}

}
}
}

#endif
