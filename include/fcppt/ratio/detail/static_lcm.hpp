//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_STATIC_LCM_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_LCM_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <fcppt/ratio/detail/static_gcd.hpp>


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
struct static_lcm
{
	static int_type const value = X / static_gcd<X, Y>::value * Y;
};

}
}
}

#endif
