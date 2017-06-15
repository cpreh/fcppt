//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NONASSIGNABLE_HPP_INCLUDED
#define FCPPT_NONASSIGNABLE_HPP_INCLUDED

#include <fcppt/detail/nonassignable.hpp>


/**
\brief Makes a class nonassignable

\ingroup fcpptvarious

Makes the class called \a classname nonassignable. The macro must be placed
inside the class definition and called with the name of the class. It deletes
the assignment operator.

Often, classes are not assignable but copyable, for example when they contain
constant elements or references. To make it clear to the compiler and to the
users that it should not be possible to assign objects of this class, this
macro should be used.

\snippet examples/noncopyable.cpp nonassignable

\param classname The name of the class
*/
#define FCPPT_NONASSIGNABLE(\
	classname\
) \
FCPPT_DETAIL_NONASSIGNABLE(\
	classname\
)

#endif
