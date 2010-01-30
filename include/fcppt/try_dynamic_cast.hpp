//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/dynamic_cast.hpp>

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
