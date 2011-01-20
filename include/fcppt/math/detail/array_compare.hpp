//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_COMPARE_HPP_INCLUDED

#include <fcppt/algorithm/compare_with.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/tr1/functional.hpp>

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
	T1 const &v1,
	T2 const &v2
)
{
	return
		algorithm::compare_with(
			v1,
			v2,
			std::tr1::bind(
				math::compare<
					typename T1::value_type
				>,
				std::tr1::placeholders::_1,
				std::tr1::placeholders::_2
			)
		);
}

}
}
}

#endif
