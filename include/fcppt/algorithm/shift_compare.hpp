//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_SHIFT_COMPARE_HPP_INCLUDED
#define FCPPT_ALGORITHM_SHIFT_COMPARE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/range/numeric.hpp>
#include <algorithm>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
/**
 * \brief Tests if \p a is equal \p b up to rotation
 * \ingroup fcpptalgorithm
 * \pre <code>Container1::value_type</code> and <code>Container2::value_type</code> have to be equality-comparable.
 *
 * Example:
 *
 * \snippet doc/algorithm.cpp shift_compare
 */
template
<
	typename Container1,
	typename Container2,
	typename Equality
>
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
				::std::bind(
					is_equal,
					*a.begin(),
					::std::placeholders::_1));

	if (first_in_second == b.end())
		return false;

	::std::rotate(
		b.begin(),
		first_in_second,
		b.end());

	return
		boost::inner_product(
			a,
			b,
			true,
			::std::logical_and<bool>(),
			is_equal);
}
}
}

#endif
