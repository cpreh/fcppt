#ifndef FCPPT_RATIO_EQUAL_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_EQUAL_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/less_equal_fwd.hpp>
#include <fcppt/ratio/less.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct less_equal
:
boost::integral_constant<
	bool,
	!less<R2, R1>::value
>
{};

}
}

#endif
