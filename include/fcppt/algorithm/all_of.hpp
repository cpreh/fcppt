//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ALL_OF_HPP_INCLUDED
#define FCPPT_ALGORITHM_ALL_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a given \p value is inside a range

\ingroup fcpptalgorithm

\tparam Pred A predicate (a unary function returning a bool)
*/
template<
	typename Range,
	typename Pred
>
inline
bool
all_of(
	Range const &_container,
	Pred const &_pred
)
{
	return
		std::find_if_not(
			_container.begin(),
			_container.end(),
			_pred
		)
		==
		_container.end();
}

}
}

#endif
