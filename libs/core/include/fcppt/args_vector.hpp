//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARGS_VECTOR_HPP_INCLUDED
#define FCPPT_ARGS_VECTOR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief A vector of command line arguments

\ingroup fcpptvarious
*/
using args_vector = std::vector<fcppt::string>;

}

#endif
