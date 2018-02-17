//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_UNIQUE_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_UNIQUE_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Removes duplicate elements from a container. Compares using a predicate.

\ingroup fcpptalgorithm

Removes duplicate elements from \p _container. Elements are compared using \p _predicate.

\tparam BinaryPredicate A function callable as <code>bool (Container::value_type, Container::value_type)</code>.
*/
template<
	typename Container,
	typename BinaryPredicate
>
void
unique_if(
	Container &_container,
	BinaryPredicate const &_predicate
)
{
	_container.erase(
		std::unique(
			_container.begin(),
			_container.end(),
			_predicate
		),
		_container.end()
	);
}

}
}

#endif
