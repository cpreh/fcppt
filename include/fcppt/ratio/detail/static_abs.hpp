#ifndef FCPPT_RATIO_DETAIL_STATIC_ABS_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_ABS_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	int_type X
>
struct static_abs
{
	static int_type const value = X < 0 ? -X : X;
};

}
}
}

#endif
