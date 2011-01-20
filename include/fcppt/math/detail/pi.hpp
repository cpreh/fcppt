//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_PI_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_PI_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct pi;

template<>
struct pi<
	long double
>
{
	static long double
	get()
	{
		return 3.1415926535897932384626433832795028841971693993751058L;
	}
};

template<>
struct pi<
	double
>
{
	static double
	get()
	{
		return 3.1415926535897932384626433832795028841971693993751058;
	}
};

template<>
struct pi<
	float
>
{
	static float
	get()
	{
		// TODO: add another constant for this!
		return static_cast<float>(
			pi<double>::get()
		);
	}
};

}
}
}

#endif
