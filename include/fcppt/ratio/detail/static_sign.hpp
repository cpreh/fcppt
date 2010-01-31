#ifndef FCPPT_RATIO_DETAIL_STATIC_SIGN_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_STATIC_SIGN_HPP_INCLUDED

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
struct static_sign
{
	static int_type const value = X == 0 ? 0 : (X < 0 ? -1 : 1);
};

}
}
}

#endif
