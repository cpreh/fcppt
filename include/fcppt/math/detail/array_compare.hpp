//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_COMPARE_HPP_INCLUDED

#include <fcppt/detail/equal.hpp>


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
array_compare(
	T1 const &_v1,
	T2 const &_v2
)
{
	return
		_v1.size() == _v2.size()
		&&
		fcppt::detail::equal(
			_v1.begin(),
			_v1.end(),
			_v2.begin()
		);
}

}
}
}

#endif
