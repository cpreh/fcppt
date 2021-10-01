//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_PARAMETERS_NO_FUNCTION_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_NO_FUNCTION_HPP_INCLUDED

#include <fcppt/log/name.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt::log
{
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::parameters parameters_no_function(fcppt::log::name &&);
}

#endif
