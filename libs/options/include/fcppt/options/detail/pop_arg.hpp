//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_POP_ARG_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_POP_ARG_HPP_INCLUDED

#include <fcppt/optional_string.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt::options::detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::optional_string
pop_arg(fcppt::reference<fcppt::options::state>, fcppt::options::parse_context const &);

}

#endif
