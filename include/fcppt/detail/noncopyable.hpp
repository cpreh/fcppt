//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_NONCOPYABLE_HPP_INCLUDED
#define FCPPT_DETAIL_NONCOPYABLE_HPP_INCLUDED

#include <fcppt/config/compiler.hpp>


#if defined(FCPPT_CONFIG_GCC_COMPILER)

#define FCPPT_DETAIL_NONCOPYABLE(\
	classname\
)\
classname(classname const &) = delete; \
classname &operator=(classname const &) = delete

#else

#define FCPPT_DETAIL_NONCOPYABLE(\
	classname\
)\
classname(classname const &); \
classname &operator=(classname const &)

#endif

#endif
