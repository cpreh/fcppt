//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LESS3_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LESS3_HPP_INCLUDED

#include <fcppt/ratio/detail/ll_mul.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	typename R1,
	typename R2,
	bool ok1,
	bool ok2
>
struct less3 // true, true and false, false
{
	static bool const value =
		ll_mul<
			R1::num,
			R2::den
		>::value
		<
		ll_mul<
			R2::num,
			R1::den
		>::value;
};

template<
	typename R1,
	typename R2
>
struct less3<R1, R2, true, false>
{
	static bool const value = true;
};

template<
	typename R1,
	typename R2
>
struct less3<R1, R2, false, true>
{
	static bool const value = false;
};

}
}
}

#endif
