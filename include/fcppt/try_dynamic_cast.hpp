//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/dynamic_cast.hpp>

/// Generates an if block with a dynamic_cast_ in its condition
/**
 * @param dest_type The type to cast to (must be a pointer)
 * @param name The name of the new variable
 * @param expression The expression to cast from
*/
#define FCPPT_TRY_DYNAMIC_CAST(\
	dest_type,\
	name,\
	expression\
)\
	if(\
		dest_type const name = \
			fcppt::dynamic_cast_<\
				dest_type\
			>(\
				expression\
			)\
	)\

#endif
