//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_MULTIPLY_HPP_INCLUDED
#define FCPPT_RATIO_MULTIPLY_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <fcppt/ratio/multiply_fwd.hpp>
#include <fcppt/ratio/object.hpp>
#include <fcppt/ratio/detail/ll_mul.hpp>
#include <fcppt/ratio/detail/static_gcd.hpp>


namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct multiply
{
private:
	static int_type const
		gcd_n1_d2 = detail::static_gcd<R1::num, R2::den>::value,
		gcd_d1_n2 = detail::static_gcd<R1::den, R2::num>::value;
public:
	typedef object<
		detail::ll_mul<R1::num / gcd_n1_d2, R2::num / gcd_d1_n2>::value,
		detail::ll_mul<R2::den / gcd_n1_d2, R1::den / gcd_d1_n2>::value
	> type;
};

}
}

#endif
