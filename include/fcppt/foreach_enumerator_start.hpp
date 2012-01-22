//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_START_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_START_HPP_INCLUDED

#include <fcppt/foreach_enumerator_start_end.hpp>

#define FCPPT_FOREACH_ENUMERATOR_START(\
	name,\
	enum_,\
	start\
)\
	FCPPT_FOREACH_ENUMERATOR_START_END(\
		name,\
		enum_,\
		start,\
		enum_::size\
	)

#endif
