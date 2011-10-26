//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_BEFORE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_BEFORE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
bool
before(
	T const &_a,
	T const &_b
)
{
	return
		std::lexicographical_compare(
			_a.begin(),
			_a.end(),
			_b.begin(),
			_b.end()
		);
}

}
}
}

#endif
