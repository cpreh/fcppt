#ifndef FCPPT_RATIO_DETAIL_STATIC_GCD_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_GCD_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>

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
struct static_gcd
{
	static int_type const value = static_gcd<Y, X % Y>::value;
};

template<
	int_type X
>
struct static_gcd<X, 0>
{
	static int_type const value = X;
};

}
}
}

#endif
