//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_GCD_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_GCD_HPP_INCLUDED

#include <fcppt/ratio/object.hpp>
#include <fcppt/ratio/detail/static_gcd.hpp>
#include <fcppt/ratio/detail/static_lcm.hpp>


namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	typename R1,
	typename R2
>
struct gcd
{
	typedef object<
		static_gcd<R1::num, R2::num>::value,
		static_lcm<R1::den, R2::den>::value
	> type;
};

}
}
}

#endif
