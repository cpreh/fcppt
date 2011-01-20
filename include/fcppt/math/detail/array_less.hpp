//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_LESS_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T1,
	typename T2
>
bool
array_less(
	T1 const &v1,
	T2 const &v2
)
{
	return
		std::lexicographical_compare(
			v1.begin(),
			v1.end(),
			v2.begin(),
			v2.end()
		);
}

}
}
}

#endif
