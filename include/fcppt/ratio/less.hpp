#ifndef FCPPT_RATIO_LESS_HPP_INCLUDED
#define FCPPT_RATIO_LESS_HPP_INCLUDED

#include <fcppt/ratio/less_fwd.hpp>
#include <fcppt/ratio/detail/less.hpp>
#include <boost/mpl/bool.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct less
:
boost::mpl::bool_<
	detail::less<
		R1,
		R2
	>::value
>
{};

}
}

#endif
