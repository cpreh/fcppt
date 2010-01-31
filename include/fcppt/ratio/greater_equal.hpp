#ifndef FCPPT_RATIO_GREATER_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_GREATER_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/greater_equal_fwd.hpp>
#include <fcppt/ratio/less.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2>

struct greater_equal
:
boost::integral_constant<
	bool,
	!less<R1, R2
>::value>
{};

}
}

#endif
