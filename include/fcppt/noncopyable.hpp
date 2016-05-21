//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NONCOPYABLE_HPP_INCLUDED
#define FCPPT_NONCOPYABLE_HPP_INCLUDED

#include <fcppt/detail/noncopyable.hpp>


/**
\brief Makes a class noncopyable

\ingroup fcpptvarious

Makes the class called \a classname noncopyable. The macro must be placed
inside the class definition and called with the name of the class. It deletes
the copy constructor and the assignment operator.

By default, C++ generates a copy constructor and assignment operator for every
class where this is possible (when its elements can all be copy constructed and
assigned). However, this is not a good default in a lot of situations where it
can be dangerous to copy an object:

<ul>
<li>If a class has already a non trivial constructor or destructor, for example
when it has to manage dynamic resources or it implements some scoped behaviour,
like for example a <code>scoped_lock</code>.</li>

<li>If an object of a class in a hierarchy gets copied, the object will be
<em>sliced</em> and not cloned. Therefore, it is often advisable to make all
classes in a hierarchy noncopyable.</li>
</ul>

\snippet examples/noncopyable.cpp noncopyable

\param classname The name of the class

\note The macro leaves a private scope behind.
*/
#define FCPPT_NONCOPYABLE(\
	classname\
) \
FCPPT_DETAIL_NONCOPYABLE(\
	classname\
)

#endif
