//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOOP_HPP_INCLUDED
#define FCPPT_LOOP_HPP_INCLUDED

#include <fcppt/loop_fwd.hpp>


namespace fcppt
{

/**
\brief Denotes a loop control statement

\ingroup fcpptvarious

Used by various algorithms that need the ability to break out of a loop early.
*/
enum class loop
{
	break_,
	continue_
};

}

#endif
