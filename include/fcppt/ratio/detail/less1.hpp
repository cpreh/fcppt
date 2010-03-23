//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LESS1_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LESS1_HPP_INCLUDED

#include <fcppt/ratio/detail/less2.hpp>
#include <fcppt/ratio/object.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	typename R1,
	typename R2,
	bool = (R1::num < R1::den == R2::num < R2::den)
>
struct less1  // N1 < D1 == N2 < D2
{
	static bool const value =
		less2<
			object<R1::num, R2::num>,
			object<R1::den, R2::den>
		>::value;
};

template<
	typename R1, 
	typename R2
>
struct less1<R1, R2, false>  // N1 < D1 != N2 < D2
{
	static bool const value = R1::num < R1::den;
};

}
}
}

#endif
