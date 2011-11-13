//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief Checks if a given value matches @a pred inside the range [@a beg @a end ]
 * \ingroup fcpptalgorithm
 * \details
 * Equivalent to find_if(beg, end, pred) != end
*/
template<
	typename In,
	typename Pred
>
bool
contains_if(
	In const beg,
	In const end,
	Pred const &pred
)
{
	return
		::std::find_if(
			beg,
			end,
			pred
		)
		!= end;
}

}
}

#endif
