//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_MAKE_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED
#define FCPPT_RANDOM_MAKE_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED

#include <fcppt/random/last_exclusive_range.hpp>

namespace fcppt
{
namespace random
{

/// Constructs a last_exclusive_range
template<
	typename T
>
last_exclusive_range<T> const
make_last_exclusive_range(
	T const &_first,
	T const &_last
)
{
	return
		random::last_exclusive_range<T>(
			_first,
			_last
		);
}

}
}

#endif
