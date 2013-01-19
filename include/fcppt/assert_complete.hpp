//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_COMPLETE_HPP_INCLUDED
#define FCPPT_ASSERT_COMPLETE_HPP_INCLUDED

/**
\brief Assert at compile time that a type is complete

\ingroup fcpptvarious

In some cases, a type must be complete, which bascially means that it is not
void and if it is a class, the definition must already be known. For example,
<code>delete</code> has undefined behaviour if it is invoked on a type that is
not complete but has a non trivial destructor.

This macro generates a compile time error if a type is not complete. An example
of its usage is shown below.

\snippet assert_complete.cpp assert_complete
*/
#define FCPPT_ASSERT_COMPLETE(\
	type\
)\
static_cast<\
	void\
>(\
	sizeof(type)\
)

#endif
