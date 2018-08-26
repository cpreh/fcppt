//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REMOVE_IF_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Removes all elements from a container matching a predicate.

\ingroup fcpptalgorithm

Removes all elements from \p _container matching \p _predicate.

\tparam Predicate A function callable as <code>bool (Container::value_type)</code>.

\return <code>true</code> if something has been removed, <code>false</code>
otherwise.
*/
template<
	typename Container,
	typename Predicate
>
bool
remove_if(
	Container &_container,
	Predicate const &_predicate
)
{
	typename Container::iterator const position(
		std::remove_if(
			_container.begin(),
			_container.end(),
			_predicate
		)
	);

	if(
		position
		==
		_container.end()
	)
		return
			false;

	_container.erase(
		position,
		_container.end()
	);

	return
		true;
}

}
}

#endif
