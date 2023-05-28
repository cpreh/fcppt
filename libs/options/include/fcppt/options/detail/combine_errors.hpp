//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options::detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::parse_error
combine_errors(fcppt::options::parse_error &&, fcppt::options::parse_error &&);
}

#endif
