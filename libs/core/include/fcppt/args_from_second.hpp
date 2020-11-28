//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARGS_FROM_SECOND_HPP_INCLUDED
#define FCPPT_ARGS_FROM_SECOND_HPP_INCLUDED

#include <fcppt/args_char.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/detail/symbol.hpp>

namespace fcppt
{
/**
\brief Copy main arguments into a container, starting from the second

\ingroup fcpptvarious
*/
FCPPT_DETAIL_SYMBOL
fcppt::args_vector args_from_second(int argc, fcppt::args_char const *const *argv);

}

#endif
