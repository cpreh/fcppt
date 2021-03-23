//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_NONMOVABLE_HPP_INCLUDED
#define FCPPT_NONMOVABLE_HPP_INCLUDED

#include <fcppt/detail/noncopyable.hpp>
#include <fcppt/detail/nonmovable.hpp>

/**
\brief Makes a class nonmovable.

\ingroup fcpptvarious

Makes the class called \a classname nonmovable and noncopyable.
The macro must be placed inside the class definition and called with the name
of the class. It deletes the move constructor, the copy constructor,
the move assignment operator and the copy assignment operator.

\param classname The name of the class.
*/
#define FCPPT_NONMOVABLE(classname) \
  FCPPT_DETAIL_NONCOPYABLE(classname); \
  FCPPT_DETAIL_NONMOVABLE(classname)

#endif
