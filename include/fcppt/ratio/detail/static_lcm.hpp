#ifndef FCPPT_RATIO_DETAIL_STATIC_LCM_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_LCM_HPP_INCLUDED

#include <fcppt/ratio/detail/static_gcd.hpp>
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
struct static_lcm
{
	static int_type const value = X / static_gcd<X, Y>::value * Y;
};

}
}
}

#endif
