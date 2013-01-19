//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/math/diff.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T1,
	typename T2,
	typename Val
>
bool
array_componentwise_equal(
	T1 const &_v1,
	T2 const &_v2,
	Val const _epsilon
)
{
	if(
		_v1.size() != _v2.size()
	)
		return false;

	typename T2::const_iterator it2(
		_v2.begin()
	);

	for(
		typename T1::const_iterator it1(
			_v1.begin()
		);
		it1 != _v1.end();
		++it1, ++it2
	)
		if(
			fcppt::math::diff(
				*it1,
				*it2
			)
			>
			_epsilon
		)
			return false;

	return true;
}

}
}
}

#endif
