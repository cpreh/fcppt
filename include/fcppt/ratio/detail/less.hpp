#ifndef FCPPT_RATIO_DETAIL_LESS_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LESS_HPP_INCLUDED

#include <fcppt/ratio/detail/static_sign.hpp>
#include <fcppt/ratio/detail/less1.hpp>
#include <fcppt/ratio/int_type.hpp>
#include <fcppt/ratio/object.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	typename R1,
	typename R2,
	int_type S1 = static_sign<R1::num>::value,
 	int_type S2 = static_sign<R2::num>::value
>
struct less
{
	static bool const value = S1 < S2;
};

template<
	typename R1,
	typename R2
>
struct less<R1, R2, 1LL, 1LL>
{
	static bool const value = less1<R1, R2>::value;
};

template<
	typename R1,
	typename R2
>
struct less<R1, R2, -1LL, -1LL>
{
	static bool const value
		= less1<
			object<-R2::num, R2::den>,
			object<-R1::num, R1::den>
		>::value;
};

}
}
}

#endif
