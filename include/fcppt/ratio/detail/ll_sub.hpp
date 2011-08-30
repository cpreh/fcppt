//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LL_SUB_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LL_SUB_HPP_INCLUDED

#include <fcppt/ratio/detail/static_sign.hpp>
#include <fcppt/ratio/detail/min_c.hpp>
#include <fcppt/ratio/int_type.hpp>
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
	int_type Y,
	int_type = static_sign<Y>::value
>
struct ll_sub;

template<
	int_type X,
	int_type Y
>
struct ll_sub<X, Y, 1>
{
private:
	static int_type const
		min = min_c,
		max = -min;

	BOOST_STATIC_ASSERT(
		min + Y <= X
	);
public:
	static int_type const value = X - Y;
};

template<
	int_type X,
	int_type Y
>
struct ll_sub<X, Y, 0>
{
	static int_type const value = X;
};

template<
	int_type X,
	int_type Y
>
struct ll_sub<X, Y, -1>
{
private:
	static int_type const
		min = min_c,
		max = -min;

	BOOST_STATIC_ASSERT(
		X <= max + Y
	);
public:
	static int_type const value = X - Y;
};

}
}
}

#endif
