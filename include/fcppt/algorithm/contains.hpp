//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{

/// This is just a small wrapper around std::find to check if @a value is inside @a beg and @a end
template<
	typename In,
	typename T
>
bool
contains(
	In const beg,
	In const end,
	T const &value
)
{
	return
		std::find(
			beg,
			end,
			value
		)
		!= end;
}

}
}

#endif
