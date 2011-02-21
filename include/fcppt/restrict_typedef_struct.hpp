//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RESTRICT_TYPEDEF_STRUCT_HPP_INCLUDED
#define FCPPT_RESTRICT_TYPEDEF_STRUCT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>

#define FCPPT_RESTRICT_TYPEDEF_STRUCT(\
	classname\
) \
private: \
classname(); \
~classname(); \
FCPPT_NONCOPYABLE(\
	classname\
)

#endif
