//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED

#include <fcppt/algorithm/remove_if.hpp>


namespace fcppt
{
namespace algorithm
{

///
/**
 * \brief Tries to remove all elements from \p _container matching \p _element
 * \ingroup fcpptalgorithm
 * \return true if something has been removed, false otherwise
*/
template<
	typename Container
>
bool
remove(
	Container &_container,
	typename Container::const_reference _element
)
{
	return
		fcppt::algorithm::remove_if(
			_container,
			[
				_element
			](
				typename Container::const_reference _ref
			)
			{
				return
					_element
					==
					_ref;
			}
		);
}

}
}

#endif
