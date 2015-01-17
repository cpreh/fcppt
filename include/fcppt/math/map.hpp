//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MAP_HPP_INCLUDED
#define FCPPT_MATH_MAP_HPP_INCLUDED

#include <fcppt/algorithm/array_map.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Convenience wrapper for fcppt::algorithm::array_map

\ingroup fcpptmath
*/
template<
	typename Dest,
	typename Source,
	typename Function
>
Dest
map(
	Source const &_source,
	Function const &_function
)
{
	return
		Dest(
			fcppt::algorithm::array_map<
				typename Dest::storage_type
			>(
				_source.storage(),
				_function
			)
		);
}

}
}

#endif
