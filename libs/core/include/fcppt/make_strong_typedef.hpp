//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_MAKE_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>


/**
\brief Creates a new strong typedef using strong_typedef.
\ingroup fcpptstrongtypedef
\param type The type to be wrapped.
\param name The name of the new typedef

Read the \link fcpptstrongtypedef module description \endlink for more information.
*/
#define FCPPT_MAKE_STRONG_TYPEDEF(\
	type,\
	name\
)\
struct fcppt_strong_typedef_##name##_tag\
{};\
\
typedef fcppt::strong_typedef<\
	type,\
	fcppt_strong_typedef_##name##_tag\
> name

#endif
