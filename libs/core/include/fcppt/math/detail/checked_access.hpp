//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
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
	fcppt::math::size_type N,
	typename T
>
inline
fcppt::container::to_reference_type<
	T
>
checked_access(
	T &_value
)
{
	typedef
	typename
	T::static_size
	static_size;

	static_assert(
		N < static_size::value,
		"Out of bounds operator[] access to a math type"
	);

	return
		_value[
			N
		];
}

}
}
}

#endif
