//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_START_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_START_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/foreach_enumerator_start_end.hpp>


/**
\brief Iterates over an enum with a designated start

\ingroup fcpptenum

Iterates over the type <code>enum_</code>, giving the loop variable the name \a
name, starting at the enumerator \a start and ending at the enum's size minus
one.

\see FCPPT_FOREACH_ENUMERATOR_START_END
*/
#define FCPPT_FOREACH_ENUMERATOR_START(\
	name,\
	enum_,\
	start\
)\
	FCPPT_FOREACH_ENUMERATOR_START_END(\
		name,\
		enum_,\
		start,\
		fcppt::enum_size<\
			enum_\
		>::value\
	)

#endif
