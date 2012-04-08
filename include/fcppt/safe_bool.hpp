//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SAFE_BOOL_HPP_INCLUDED
#define FCPPT_SAFE_BOOL_HPP_INCLUDED


/**
\brief Implements the safe bool idiom for a class

\ingroup fcpptvarious

Implements the safe bool idiom for a class called \a classname. The macro must
be placed inside the class definition and called with the name of the class.

It generates a member function that makes it possible to use objects of this
class as a condition like in <code>if(object)</code>. However, objects
of this class are not convertible to <code>bool</code> or any other integral
types.

To tell when the expression <code>object</code> should evaluate to
<code>true</code>, the member function <code>bool boolean_test() const</code>
must be implemented.

In the following example, a class is defined using the safe bool idiom:

\snippet safe_bool.cpp safe_bool_declaration

An object of this class can then be used in an if statement:

\snippet safe_bool.cpp safe_bool_usage

\param classname The name of the class

\note The macro leaves a public scope behind.
*/
#define FCPPT_SAFE_BOOL(\
	classname\
)\
private: \
\
typedef void (classname::*bool_type)() const; \
\
void \
safe_bool_reference_function() const \
{}\
\
public: \
\
operator bool_type() const \
{\
	return \
		classname::boolean_test()\
		?\
			&classname::safe_bool_reference_function \
		:\
			bool_type() \
		;\
}

#endif
