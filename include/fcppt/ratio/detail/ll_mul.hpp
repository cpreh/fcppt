//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LL_MUL_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LL_MUL_HPP_INCLUDED

#include <fcppt/ratio/detail/static_abs.hpp>
#include <fcppt/ratio/detail/min_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	int_type X,
	int_type Y
>
struct ll_mul
{
private:
	static int_type const
		min = min_c::value,
		nan = min - 1,
		max = -min,
		a_x = static_abs<X>::value,
		a_y = static_abs<Y>::value;

	BOOST_STATIC_ASSERT(
		X != nan
	);

	BOOST_STATIC_ASSERT(
		Y != nan
	);

	BOOST_STATIC_ASSERT(
		a_x <= max / a_y
	);
public:
	static int_type const value = X * Y;
};

template<
	int_type Y
>
struct ll_mul<0, Y>
{
	static int_type const value = 0;
};

template<
	int_type X
>
struct ll_mul<X, 0>
{
	static int_type const value = 0;
};

template <>
struct ll_mul<0, 0>
{
	static int_type const value = 0;
};

}
}
}

#endif
