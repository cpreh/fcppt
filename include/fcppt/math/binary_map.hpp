//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BINARY_MAP_HPP_INCLUDED
#define FCPPT_MATH_BINARY_MAP_HPP_INCLUDED

#include <fcppt/algorithm/array_binary_map.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Convenience wrapper for fcppt::algorithm::array_binary_map

\ingroup fcpptmath
*/
template<
	typename Dest,
	typename Source1,
	typename Source2,
	typename Function
>
Dest
binary_map(
	Source1 const &_source1,
	Source2 const &_source2,
	Function const &_function
)
{
	return
		Dest(
			fcppt::algorithm::array_binary_map<
				typename Dest::storage_type
			>(
				_source1.storage(),
				_source2.storage(),
				_function
			)
		);
}

}
}

#endif
