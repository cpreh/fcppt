//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ABSURD_HPP_INCLUDED
#define FCPPT_ABSURD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief The polymorphic terminate function

\ingroup fcpptvarious

Terminates the program but can be used where an expression of any type is
required.
*/
template <typename T>
inline T absurd()
{
  std::terminate();
}

}

#endif
