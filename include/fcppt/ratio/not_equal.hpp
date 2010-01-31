#ifndef FCPPT_RATIO_NOT_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_NOT_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/not_equal.hpp>
#include <fcppt/ratio/equal.hpp>
#include <boost/mpl/not.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct not_equal
:
boost::mpl::not_<
	equal<
		R1,
		R2
	>
>
{};

}
}

#endif
