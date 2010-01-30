//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_INCLUSIVE_RANGE_HPP_INCLUDED
#define FCPPT_RANDOM_INCLUSIVE_RANGE_HPP_INCLUDED

#include <fcppt/random/range.hpp>

namespace fcppt
{
namespace random
{

template<
	typename T
>
class inclusive_range
:
	public range<T>
{
public:
	inclusive_range(
		T const &first_,
		T const &last_
	)
	:
		range<T>(
			first_,
			last_
		)
	{}
};

template<
	typename T
>
inclusive_range<T> const
make_inclusive_range(
	T const &first,
	T const &last
)
{
	return inclusive_range<T>(
		first,
		last
	);
}

}
}

#endif
