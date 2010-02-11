//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_POW_INT_HPP_INCLUDED
#define FCPPT_MATH_POW_INT_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace math
{

template<
	typename Base,
	typename Exp
>
typename boost::enable_if<
	boost::is_integral<
		Base
	>,
	Base
>::type
pow_int(
	Base const base,
	Exp const e
)
{
	if(e == 0)
		return 1;
	Base ret = base;
	for(Exp i = 1; i < e; ++i)
		ret *= base;
	return ret;
}

}
}

#endif
