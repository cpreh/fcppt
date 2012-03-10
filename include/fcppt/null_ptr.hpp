//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NULL_PTR_HPP_INCLUDED
#define FCPPT_NULL_PTR_HPP_INCLUDED

#include <fcppt/null_ptr_t.hpp>


namespace fcppt
{

/**
\brief Partial replacement for C++11's nullptr

This function is a partial replacement for C++11's <code>nullptr</code>. It can
be used for pointers to objects and pointers to functions only. Member function
pointers are currently not supported.

The reason for this function's existance is that the literal <code>0</code> or
the macro <code>NULL</code> can be misused in C++ because they are convertible
to a lot of other things. Here is an example:

\snippet null_ptr.cpp null_ptr_funcs

\snippet null_ptr.cpp null_ptr_call

\return An object that is implicitly convertible to null pointers
*/
inline
fcppt::null_ptr_t const
null_ptr()
{
	return fcppt::null_ptr_t();
}

}

#endif
