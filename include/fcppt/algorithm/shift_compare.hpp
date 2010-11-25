//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SHIFT_COMPARE_HPP_INCLUDED
#define FCPPT_ALGORITHM_SHIFT_COMPARE_HPP_INCLUDED

#include <fcppt/tr1/functional.hpp>
#include <fcppt/algorithm/inner_product.hpp>
#include <algorithm>
#include <functional>

namespace fcppt
{
namespace algorithm
{
template<typename Container1,typename Container2,typename Equality>
bool
shift_compare(
	Container1 const &a,
	Container2 b,
	Equality const &is_equal)
{
	// Has to be an iterator so the mutating algorithm below works
	typename Container2::iterator 
		first_in_second = 
			::std::find_if(
				b.begin(),
				b.end(),
				::std::tr1::bind(
					is_equal,
					*a.begin(),
					::std::tr1::placeholders::_1));

	if (first_in_second == b.end())
		return false;

	::std::rotate(
		b.begin(),
		first_in_second,
		b.end());

	return 
		fcppt::algorithm::inner_product(
			a,
			b,
			true,
			::std::logical_and<bool>(),
			is_equal);
}
}
}

#endif
