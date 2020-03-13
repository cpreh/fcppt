//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NONCOPYABLE_HPP_INCLUDED
#define FCPPT_NONCOPYABLE_HPP_INCLUDED

#include <fcppt/detail/noncopyable.hpp>


/**
\brief Makes a class noncopyable.

\ingroup fcpptvarious

Makes the class called \a classname noncopyable. The macro must be placed
inside the class definition and called with the name of the class. It deletes
the copy constructor and the assignment operator.

\snippet examples/noncopyable.cpp noncopyable

\param classname The name of the class.
*/
#define FCPPT_NONCOPYABLE(\
	classname\
) \
FCPPT_DETAIL_NONCOPYABLE(\
	classname\
)

#endif
