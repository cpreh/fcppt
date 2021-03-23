//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_LEFTOVER_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_LEFTOVER_ERROR_HPP_INCLUDED

#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/optional_error.hpp>
#include <fcppt/options/detail/symbol.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::detail::optional_error leftover_error(fcppt::options::state const &);

}
}
}

#endif
