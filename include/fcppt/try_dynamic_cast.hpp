//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_TRY_DYNAMIC_CAST_HPP_INCLUDED


/**
\brief Generates an if block with a dynamic_cast in its condition

\ingroup fcpptcasts

Generates an if block, trying to cast \a expression to \a dest_type, giving the
variable the name \a name. If the cast does not succeeed, then the if block
will not be taken.

\snippet dynamic_cast.cpp try_dynamic_cast

\param dest_type The type to cast to (must be a pointer)

\param name The name of the new variable

\param expression The expression to cast from
*/
#define FCPPT_TRY_DYNAMIC_CAST(\
	dest_type,\
	name,\
	expression\
)\
	if(\
		dest_type const name = \
			dynamic_cast<\
				dest_type\
			>(\
				expression\
			)\
	)\

#endif
