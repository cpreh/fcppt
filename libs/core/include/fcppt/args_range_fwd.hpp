//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARGS_RANGE_FWD_HPP_INCLUDED
#define FCPPT_ARGS_RANGE_FWD_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/iterator/range_fwd.hpp>

namespace fcppt
{
/**
\brief A view over command line arguments

\ingroup fcpptvarious
*/
using args_range = fcppt::iterator::range<fcppt::args_vector::const_iterator>;

}

#endif
