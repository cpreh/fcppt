//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DUAL_OPTION_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_OPTIONS_DUAL_OPTION_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/options/dual_option_error_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options
{
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::io::ostream &
operator<<(fcppt::io::ostream &, fcppt::options::dual_option_error const &);
}

#endif
