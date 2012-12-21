//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
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
\brief Checks if a given value matches @a pred inside the range [\p beg \p end]
\ingroup fcpptalgorithm
\tparam In A forward iterator
\tparam Pred A predicate (a unary function returning a bool)

This is equivalent to

\code
std::find_if(beg, end, pred) != end
\endcode
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

/**
\brief Checks if a given \p value is inside a range
\ingroup fcpptalgorithm
\tparam Container A container type having <code>begin</code> and <code>end</code> member functions
\tparam Pred A predicate (a unary function returning a bool)

This is equivalent to

This is equivalent to
\code
contains_if(container.begin(), container.end(), value)
\endcode
*/
template<
	typename Container,
	typename Pred
>
bool
contains_if(
	Container const &container,
	Pred const &pred
)
{
	return
		::std::find_if(
			container.begin(),
			container.end(),
			pred
		)
		!= container.end();
}
}
}

#endif
