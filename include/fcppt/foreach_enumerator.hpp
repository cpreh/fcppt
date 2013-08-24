//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_HPP_INCLUDED

#include <fcppt/foreach_enumerator_start.hpp>
#include <fcppt/cast/int_to_enum.hpp>


/**
\brief Iterates over an enum

\ingroup fcpptenum

Iterates over the type <code>enum_</code>, giving the loop variable the name \a
name, starting at <code>static_cast<enum_>(0)</code> and ending at the enum's
size minus one.

\snippet foreach_enumerator.cpp foreach_enumerator_declaration

\snippet foreach_enumerator.cpp foreach_enumerator
*/
#define FCPPT_FOREACH_ENUMERATOR(\
	name,\
	enum_\
)\
	FCPPT_FOREACH_ENUMERATOR_START(\
		name,\
		enum_, \
		fcppt::cast::int_to_enum<\
			enum_\
		>(\
			0\
		)\
	)

#endif
