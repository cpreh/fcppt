//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2011 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LESS2_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LESS2_HPP_INCLUDED

#include <fcppt/ratio/detail/min_c.hpp>
#include <fcppt/ratio/detail/less3.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template <
	typename R1,
	typename R2,
	bool = (R1::num < R1::den == R2::num < R2::den)
>
struct less2  // N1 < D1 == N2 < D2
{
	static int_type const max = -min_c::value;

	static bool const
		ok1 = R1::num <= max / R2::den,
		ok2 = R2::num <= max / R1::den,
		value = less3<R1, R2, ok1, ok2>::value;
};

template<
	typename R1,
	typename R2
>
struct less2<R1, R2, false>  // N1 < D1 != N2 < D2
{
	static bool const value = R1::num < R1::den;
};

}
}
}

#endif
