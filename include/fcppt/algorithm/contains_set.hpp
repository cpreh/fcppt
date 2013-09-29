//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_CONTAINS_SET_HPP_INCLUDED
#define FCPPT_ALGORITHM_CONTAINS_SET_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Checks if a set contains a key
\ingroup fcpptalgorithm
*/
template<
	typename Set
>
bool
contains_set(
	Set const &_set,
	typename Set::key_type const &_key
)
{
	return
		_set.find(
			_key
		)
		!=
		_set.end();
}

}
}

#endif
