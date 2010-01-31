#ifndef FCPPT_RATIO_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/greater_fwd.hpp>
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
struct ratio_greater
:
boost::integral_constant<
	bool,
	less<R2, R1>::value
>
{};

}
}

#endif
