//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_START_END_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_START_END_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


/**
\brief Iterates over an enum with designated start and end values

\ingroup fcpptvarious

Iterates over the type <code>enum_::type</code>, giving the loop variable the
name \a name, starting at the enumerator \a start and ending before \a end
(which means \a end itself is not included).

This macro generates a for loop that hides some enum casting behind its scenes.
It is important that the enumerators in the enum are contiguous as in the
following example:

\snippet foreach_enumerator.cpp foreach_enumerator_declaration

\snippet foreach_enumerator.cpp foreach_enumerator_start_end

\see FCPPT_FOREACH_ENUMERATOR

\see FCPPT_FOREACH_ENUMERATOR_START_END
*/
#define FCPPT_FOREACH_ENUMERATOR_START_END(\
	name,\
	enum_,\
	start,\
	end\
)\
for(\
	enum_ name{\
		start\
	};\
	static_cast<\
		std::underlying_type< \
			enum_ \
		>::type\
	>(\
		name\
	) \
	< \
	static_cast<\
		std::underlying_type< \
			enum_ \
		>::type\
	>(\
		end\
	);\
	name = \
		static_cast<\
			enum_\
		>(\
			static_cast<\
				std::underlying_type< \
					enum_ \
				>::type\
			>(\
				name\
			)\
			+ \
			1\
		)\
)

#endif
