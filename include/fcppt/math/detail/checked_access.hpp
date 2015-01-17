//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CHECKED_ACCESS_HPP_INCLUDED

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
typename
std::conditional<
	std::is_const<
		T
	>::value,
	typename T::const_reference,
	typename T::reference
>::type
checked_access(
	T &_value
)
{
	typedef typename T::dim_wrapper dim_wrapper;

	static_assert(
		N < dim_wrapper::value,
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
