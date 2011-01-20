//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SAFE_BOOL_HPP_INCLUDED
#define FCPPT_SAFE_BOOL_HPP_INCLUDED

#define FCPPT_SAFE_BOOL(x)\
typedef void (x::*bool_type)() const; \
void safe_bool_reference_function() const {}\
public: \
operator bool_type() const\
{\
	return x::boolean_test()\
		? &x::safe_bool_reference_function \
		: 0;\
}

#endif
