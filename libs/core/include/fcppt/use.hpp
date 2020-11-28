//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_USE_HPP_INCLUDED
#define FCPPT_USE_HPP_INCLUDED

/**
\brief Uses an argument

\ingroup fcpptvarious

This is useful in situations where an argument is only used for its type.
*/
#define FCPPT_USE(name) static_cast<void>(name)

#endif
