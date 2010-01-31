#ifndef FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_MIN_C_HPP_INCLUDED

#include <fcppt/ratio/int_type.hpp>
#include <climits>

namespace fcppt
{
namespace ratio
{
namespace detail
{

int_type const min_c =
	(static_cast<int_type>(1)
	<< (sizeof(int_type) * CHAR_BIT - 1)) + 1;

}
}
}

#endif
