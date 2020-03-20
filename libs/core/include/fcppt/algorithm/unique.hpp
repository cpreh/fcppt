//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_UNIQUE_HPP_INCLUDED
#define FCPPT_ALGORITHM_UNIQUE_HPP_INCLUDED

#include <fcppt/algorithm/unique_if.hpp>
#include <fcppt/type_traits/value_type.hpp>


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
	using
	value_type
	=
	fcppt::type_traits::value_type<
		Container
	>;

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
