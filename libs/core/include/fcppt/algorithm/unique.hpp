//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_UNIQUE_HPP_INCLUDED
#define FCPPT_ALGORITHM_UNIQUE_HPP_INCLUDED

#include <fcppt/algorithm/unique_if.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Removes duplicate elements from a container.

\ingroup fcpptalgorithm

Removes duplicate elements from \p _container.
*/
template<
	typename Container
>
inline
void
unique(
	Container &_container
)
{
	typedef
	typename
	Container::value_type
	value_type;

	return
		fcppt::algorithm::unique_if(
			_container,
			[](
				value_type const &_v1,
				value_type const &_v2
			)
			{
				return
					_v1
					==
					_v2;
			}
		);
}

}
}

#endif
