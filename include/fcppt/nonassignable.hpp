//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NONASSIGNABLE_HPP_INCLUDED
#define FCPPT_NONASSIGNABLE_HPP_INCLUDED

#define FCPPT_NONASSIGNABLE(\
	classname\
) \
private: \
classname &operator=(classname const &)

#endif
