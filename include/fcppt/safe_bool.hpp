//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SAFE_BOOL_HPP_INCLUDED
#define FCPPT_SAFE_BOOL_HPP_INCLUDED


#define FCPPT_SAFE_BOOL(\
	classname\
)\
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
